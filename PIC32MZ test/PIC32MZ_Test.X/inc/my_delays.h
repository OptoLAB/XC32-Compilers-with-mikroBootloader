/* 
 * File:   my_delays.h
 * Author: Jovan
 *
 */
#ifndef MY_DELAYS_H
#define	MY_DELAYS_H

#include <xc.h>

#define _XTAL_FREQ   (200000000UL)    // system clock

void delay_ms(unsigned long delay); 
void delay_us(unsigned long delay);

#endif	/* MY_DELAYS_H */

