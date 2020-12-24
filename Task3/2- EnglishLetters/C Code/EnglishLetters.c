/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/31/2020
Author  : Roozbeh Aghili
Company : Kharazmi University
Comments: Creating a LCD showing English Letters on it


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <stdio.h>
#include <alcd.h>

int initial = 65;
int timerOverflow = 0;

interrupt [TIM1_OVF] void timer1_ovf_isr(void){
    if(initial < 91){
        timerOverflow++;
        if(timerOverflow == 40)
        {
            char buffer[100];    
            sprintf(buffer, "%c",(char) initial );
            lcd_puts(buffer);
            initial++;
            timerOverflow = 0;  
        }
    }
    
    TCNT1H = 0xFF;
    TCNT1L = 0xFE;
}

void main(void){
lcd_init(20);

TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (1<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H = 0xFF;
TCNT1L = 0xFE;
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

#asm("sei")
while (1){}
}
