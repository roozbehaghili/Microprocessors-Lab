/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/25/2020
Author  : Roozbeh Aghili    
Company : Kharazmi University
Comments: Creating a LCD showing Hello World on it


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <alcd.h>

void main(void)
{
    lcd_init(100);     
    while (1)
    {
        lcd_gotoxy(3,1);
        lcd_putsf("Hello World :D");
    }
}