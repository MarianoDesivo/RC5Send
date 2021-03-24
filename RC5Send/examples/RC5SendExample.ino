#include "RC5_Send.h"

//An infrared LED must be connected to pin 9

void setup() {
  Rc5.Begin(); //Sets up Timer1 registers and interruption
  Serial.begin(9600); //Initialize Serial Monitor, just to print you code
  
}

void loop() {

  //Here write your device address and command
  int Address = 0x15; 
  int Command = 0x3F;

  //Print
  Serial.println();
  Serial.print(F("address=0x"));
  Serial.print(Address, HEX);
  Serial.print(F(" command=0x"));
  Serial.println(Command,HEX);
  //Send RC5
  Rc5.Send(Address,Command);

}
