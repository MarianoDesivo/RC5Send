/*
  RC5_Send.h - Library for sending RC5 code.
  Created by Mariano J. Desivo, March 18, 2021.
  Released into the public domain.
*/


#ifndef RC5_Send_h
#define RC5_Send_h

#include "RC5Send.h"

Rc5 Rc5;

//Declare each bit from IR message with example values
bool start = 1; 
bool field = 1;	
bool toggle = 1; 
volatile int address = 0b10101; //0x15s
int command = 0b111111; //0x3f
bool sendFlag=0;

ISR(TIMER1_CAPT_vect)
{
  long int codigo = (start << 13)|(field << 12)|(toggle << 11)|(address<<6)|(command); //Add message variables to one variable with the full IR message

  static int i=0; 
  static int j=0; //index of the "codigo" bit we will read
  static int espacio=0; //there must be 114ms between each IR message
  
if (sendFlag){ //activated with Send()
  if (espacio==0){
    if (bitRead(codigo,13-j)==1){ //If the bit we read is 1
      if (i<32){
        OCR1A=443; //Sends 0V
      }
      if (i>=32){
        OCR1A=319; //Then sends 32 times a 36khz pulse
      }
    }
    if (bitRead(codigo,13-j)==0){ //If the bit we read is 0
      if (i<32){
        OCR1A=319; //Sends 32 times a 36khz pulse
      }
      if (i>=32){
        OCR1A=443; //Then sends 0V
      }
     }
     
    i++; 
    if (i>63){ //We finished sending a bit, let's start with the next one
      i=0;
      j++;
    }
    
  }
  else{
    OCR1A=443; //sends 0V (in space between messages)
    espacio++;
  }
  if (j>13){ //We finished sending a message, now there must be 114ms of no signal
    espacio=1;
    j=0;}
  
  if (espacio>4200){ //space between messages ~~114ms
    espacio=0;
    sendFlag=0;} //You can use Send() again
}  
}

int Rc5::Send(int addr, int comm)
{	
    if (comm>0x3f){ //You are using extended RC5
       comm &= 0x3f; //We only need 6 bits command
       field = 0; //bit 7 from command (Extended RC5) tell us to change Field-Bit from 1 to 0 (second bit from full IR code)
    }
    address=addr;
    command=comm;
    toggle=!toggle; // Toggle-bit must change it's value on each message
    sendFlag=1;
    return address;
    return command;
    return toggle;
    return sendFlag;
    return field;
}

#endif