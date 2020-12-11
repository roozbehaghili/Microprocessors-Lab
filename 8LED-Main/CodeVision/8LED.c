/*******************************************************
Project : 8 LED 
Version : 
Date    : 2020-12-13
Author  : Roozbeh Aghili
Company : Kharazmi University

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
*******************************************************/

#include <mega16.h>
#include <delay.h>

#define LED_0 PORTB.0
#define LED_1 PORTB.1
#define LED_2 PORTB.2
#define LED_3 PORTB.3
#define LED_4 PORTB.4
#define LED_5 PORTB.5
#define LED_6 PORTB.6
#define LED_7 PORTB.7

#define onBool 1
#define offBool 0

void main(void)
{
    DDRA = 0x00;
    PINA = 0x00;
    DDRB = 0xff;
    PORTB = 0x00;
    #asm("sei")
    
    while (1) {
        if(PINA.0==1)
        {

            LED_0 = onBool;
            delay_ms(500);
            LED_0 = offBool;
            LED_1 = onBool;
            delay_ms(500);
            LED_1 = offBool;
            LED_2 = onBool;
            delay_ms(500);
            LED_2 = offBool;
            LED_3 = onBool;
            delay_ms(500);
            LED_3 = offBool;
            LED_4 = onBool;
            delay_ms(500);
            LED_4 = offBool;
            LED_5 = onBool;
            delay_ms(500);
            LED_5 = offBool;
            LED_6 = onBool;
            delay_ms(500);
            LED_6 = offBool;
            LED_7 = onBool;
            delay_ms(500);
            LED_7 = offBool;
            LED_6 = onBool;
            delay_ms(500);
            LED_6 = offBool;
            LED_5 = onBool;
            delay_ms(500);
            LED_5 = offBool;
            LED_4 = onBool;
            delay_ms(500);
            LED_4 = offBool;
            LED_3 = onBool;
            delay_ms(500);
            LED_3 = offBool;
            LED_2 = onBool;
            delay_ms(500);
            LED_2 = offBool;
            LED_1 = onBool;
            delay_ms(500);
            LED_1 = offBool;
            LED_0 = onBool;
            delay_ms(500);
            LED_0 = offBool;
            
        } else { 
            PORTB = 00000000;  
        }
    }
}
