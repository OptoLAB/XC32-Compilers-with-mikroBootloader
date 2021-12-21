/* 
 * Author: J. Bajic
 */

#include "CPUConfig.h"
#include <xc.h>
#include <sys/attribs.h>
#include "my_delays.h"


//MINI BOARD BUILTIN LEDs
#define DATA_LED_IO TRISEbits.TRISE0=0
#define STAT_LED_IO TRISEbits.TRISE1=0
#define DATA_LED(bit) LATEbits.LATE0=bit 
#define STAT_LED(bit) LATEbits.LATE1=bit 


//https://www.aidanmocke.com/blog/2018/04/03/config/
void set_performance_mode()
{   
    
    unsigned int cp0;

    // Unlock Sequence
    asm volatile("di"); // Disable all interrupts
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;  

    // PB1DIV
    // Peripheral Bus 1 cannot be turned off, so there's no need to turn it on
    PB1DIVbits.PBDIV = 1; // Peripheral Bus 1 Clock Divisor Control (PBCLK1 is SYSCLK divided by 2)

    // PB2DIV
    PB2DIVbits.ON = 1; // Peripheral Bus 2 Output Clock Enable (Output clock is enabled)
    PB2DIVbits.PBDIV = 1; // Peripheral Bus 2 Clock Divisor Control (PBCLK2 is SYSCLK divided by 2)

    // PB3DIV
    PB3DIVbits.ON = 1; // Peripheral Bus 2 Output Clock Enable (Output clock is enabled)
    PB3DIVbits.PBDIV = 1; // Peripheral Bus 3 Clock Divisor Control (PBCLK3 is SYSCLK divided by 2)

    // PB4DIV
    PB4DIVbits.ON = 1; // Peripheral Bus 4 Output Clock Enable (Output clock is enabled)
    while (!PB4DIVbits.PBDIVRDY); // Wait until it is ready to write to
    PB4DIVbits.PBDIV = 0; // Peripheral Bus 4 Clock Divisor Control (PBCLK4 is SYSCLK divided by 1)

    // PB5DIV
    PB5DIVbits.ON = 1; // Peripheral Bus 5 Output Clock Enable (Output clock is enabled)
    PB5DIVbits.PBDIV = 1; // Peripheral Bus 5 Clock Divisor Control (PBCLK5 is SYSCLK divided by 2)

    // PB7DIV
    PB7DIVbits.ON = 1; // Peripheral Bus 7 Output Clock Enable (Output clock is enabled)
    PB7DIVbits.PBDIV = 0; // Peripheral Bus 7 Clock Divisor Control (PBCLK7 is SYSCLK divided by 1)

    // PB8DIV
    PB8DIVbits.ON = 1; // Peripheral Bus 8 Output Clock Enable (Output clock is enabled)
    PB8DIVbits.PBDIV = 1; // Peripheral Bus 8 Clock Divisor Control (PBCLK8 is SYSCLK divided by 2)

    // PRECON - Set up prefetch
    PRECONbits.PFMSECEN = 0; // Flash SEC Interrupt Enable (Do not generate an interrupt when the PFMSEC bit is set)
    PRECONbits.PREFEN = 3; // Predictive Prefetch Enable (Enable predictive prefetch for any address)
    PRECONbits.PFMWS = 3; // PFM Access Time Defined in Terms of SYSCLK Wait States (Two wait states)
    
    //INTCONbits.MVEC = 1;
    // Set up caching
    cp0 = _mfc0(16, 0);
    cp0 &= ~0x07;
    cp0 |= 0b011; // K0 = Cacheable, non-coherent, write-back, write allocate
    _mtc0(16, 0, cp0);  

    // Lock Sequence
    SYSKEY = 0x33333333;
    asm volatile("ei"); // Enable all interrupts
}


void init(void)
{ 
    set_performance_mode();

    // Set all of PORT pins to digital
    ANSELB = 0;
    ANSELE = 0;
    ANSELG = 0;
    
    DATA_LED_IO;
    STAT_LED_IO;
}

void main(void) 
{
    init();
   
    while(1)
    {
       DATA_LED(1); STAT_LED(0); 
       delay_ms(500);
       DATA_LED(0); STAT_LED(1); 
       delay_ms(500);
    }
}