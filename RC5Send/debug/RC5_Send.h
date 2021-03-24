#include "RC5Send.h"

Rc5 Rc5;

bool start = 1;
bool field = 1;
bool toggle = 1;
volatile int address = 0b10101; //0x15
int command = 0b111111; //0x3f
bool sendFlag=0;

ISR(TIMER1_CAPT_vect)
{
  long int codigo = (start << 13)|(field << 13)|(toggle << 11)|(address<<6)|(command); //0x153f

  static int i=0;
  static int j=0;
  static int espacio=0;
  
if (sendFlag){
  if (espacio==0){
    if (bitRead(codigo,13-j)==1){
      if (i<32){
        OCR1A=443; //manda 0V planchado
      }
      if (i>=32){
        OCR1A=319; //mando pulsos 36khz
      }
    }
    if (bitRead(codigo,13-j)==0){
      if (i<32){
        OCR1A=319; //mando pulsos 36khz
      }
      if (i>=32){
        OCR1A=443; //manda 0V planchado
      }
     }
     
    i++; 
    if (i>63){
      i=0;
      j++;
    }
    
  }
  else{
    OCR1A=443; //espacio
    espacio++;
  }
  if (j>13){
    espacio=1;
    j=0;}
  
  if (espacio>4200){ //espacio entre mensajes ~~114ms
    espacio=0;
    sendFlag=0;}
}  
}

int Rc5::Send(int addr, int comm)
{	
    if (comm>0x3f){ //You are using extended RC5
       comm &= 0x3f; //We only need 6 bits command
       field = 0; //bit 7 from command tell us to change Field-Bit from 1 to 0 (second bit from full IR code)
    }
    address=addr;
    command=comm;
    toggle=!toggle; // Toggle-bit must change it's value on each message
    sendFlag=1;
    return address;
    return command;
}
