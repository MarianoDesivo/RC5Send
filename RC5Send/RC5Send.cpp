/*
  RC5Send.cpp - Library for sending RC5 code.
  Created by Mariano J. Desivo, March 18, 2021.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RC5Send.h"



Rc5::Rc5(void){

}


void Rc5::Begin(void) //Setups registers for AtMega328p 
{
 //Timer1 Settings
 // set inverting mode
 // set Fast PWM mode using ICR1 as TOP
  TCCR1A=0b11000010;
  TCCR1B=0b00011001;
      // Start the timer with no prescaler
  
  TIMSK1 = 0x20; // Enables the interruption when TCNT reachs ICR1 (once each 36k^-1 seconds)
  
  ICR1 = 443; // 16M/(1*(1+443) = 36khz
  OCR1A = 319; //duty cycle 443/124 = 28%
  DDRB |= 0b10; // Enables PWM output on pin9 (OC1A)
  sei(); // set Global Interrupt Enable
  

}

void Rc5::print(char string[])
{
  Serial.print(string); //debug function
}

