/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/19/2020
Author  : Roozbeh Aghili
Company : Kharazmi University
Comments: 0 to 9999 using four 7-segments


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <stdio.h>
#include <delay.h>


int temp;
int counter0 = 0; 
int counter1 = 0;  
int SevenSeg[10] = {0b10111111, 0b10000110, 0b11011011, 0b11001111, 0b1100110, 0b11101101, 0b11111101, 0b10000111, 0b11111111, 0b11101111 };
int SevenSegCounter[4] = {0,0,0,0};

int i = 3;
int lastSevenSeg = 3;
int temp;

interrupt [TIM0_OVF] void timer0_ovf_isr(void){
       counter0++;     
       if(counter0 == 2){
           temp = PORTC ^ 0b11111111;
           PORTC= temp ^ 0b11111111;
           PORTD = SevenSeg[SevenSegCounter[lastSevenSeg]];
           temp = temp >>1; 
           if(temp == 0){
           temp = 8;    }    
           temp = temp ^ 0b11111111;
           PORTC = temp;
           temp = temp ^ 0b11111111;
             counter0 = 0;
             lastSevenSeg--;  
             if(lastSevenSeg == -1 ){        
             lastSevenSeg = 3; }}      
       TCNT0=0x00;}

interrupt [TIM1_OVF] void timer1_ovf_isr(void){
        counter1++;
    if(counter1 == 150){
         SevenSegCounter[3]++;
         while (i>=0){
            if( SevenSegCounter[i] ==10){
            SevenSegCounter[i-1]++;
            SevenSegCounter[i]=0;
            }      
             i--;
         }
             i = 3;
             counter1 = 0; }
        TCNT1H=0xFF;
        TCNT1L=0xF0;}         
        
void main(void){
    DDRD = 0xFF;
    DDRC = 0xFF;
    PORTC = 0xEF;   
    TCCR0=0x05;
    TCNT0=0x00;
    OCR0=0x00;   
	TCCR1A = 0x00;
	TCCR1B = 0x05;  
    TCNT1H = 0xFF;  
    TCNT1L = 0xF0; 
    MCUCR =(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR =(0<<ISC2);
	TIMSK = 0x05;   
    #asm ("sei")   
    
    while(1){}
} 
