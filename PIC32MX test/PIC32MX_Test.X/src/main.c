/* 
 * Author: Jovan
 */
#include "CPUConfig.h"
#include <xc.h>
#include <sys/attribs.h>
#include "my_delays.h"


//MINI BOARD BUILTIN LEDs
#define DATA_LED_IO TRISDbits.TRISD6=0
#define STAT_LED_IO TRISGbits.TRISG6=0 // USED AS SCK2
#define DATA_LED(bit) LATDbits.LATD6=bit 
#define STAT_LED(bit) LATGbits.LATG6=bit // USED AS SCK2


void Init(void)
{     
    asm volatile("di");         // Disable all interrupts
   
    CHECONbits.DCSZ = 3;        //Data Cache Size in Lines bits - enable data caching with 4 lines
    CHECONbits.PFMWS = 7;       //PFM Access Time Defined in Terms of SYSLK Wait States bit - 2 wait states
    CHECONbits.PREFEN = 3;      //Enable predictive prefetch for both cacheable and non-cacheable regions
    BMXCONbits.BMXWSDRM = 1;    //Data RAM accesses from CPU have zero wait states for address setup
    INTCONbits.MVEC = 1;        //Interrupt controller configured for Multi-vector mode
    DDPCONbits.JTAGEN = 0;      //Disable the JTAG port
    AD1PCFG = 0xFFFF;
    
    DATA_LED_IO;
    STAT_LED_IO;   
    
    asm volatile("ei");         // Enable all interrupts 
}


void main(void) 
{
    Init();
 
    while(1)
    {
       DATA_LED(1); STAT_LED(0); 
       delay_ms(500);
       DATA_LED(0); STAT_LED(1); 
       delay_ms(500);
    }
}

