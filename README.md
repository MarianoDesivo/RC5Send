# Rc5Send

I made this because other libraries would not work on my Phillip devices.

Using the Timer1 registers, from Atmega328P microprocessor, Arduino sends a PWM signal to build the RC5 messages.

## Prerequisites

* Arduino UNO (haven't tested in other devices but should work)
* Infrared LED
* 47-220ohm resistor

## Specifications

I followed the specifications below. Burst is set at 36kHz with a Duty Cycle of 28%, using Fast PWM from [Atmega328P](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf).

![image](https://user-images.githubusercontent.com/79780807/112241629-66223e00-8c29-11eb-83ef-01184de6e994.png)

## Installing Rc5Send

To install Rc5Send, follow these steps:

* Download [Rc5Send as .zip](https://github.com/MarianoDesivo/RC5Send/archive/refs/heads/main.zip).
* Extract the RC5Send folder.
* Move it to your library folder. For example "C:\Users\MARIANO\Documents\Arduino\libraries".

## Using Rc5Send

```ino
#include "RC5_Send.h"

//An infrared LED must be connected to pin 9

void setup() {
  Rc5.Begin(); //Sets up Timer1 registers and interruption
  Serial.begin(9600); //Initialize Serial Monitor, just to print your code
  
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
```

## Wiring diagram

![image](https://user-images.githubusercontent.com/79780807/112244339-e8acfc80-8c2d-11eb-9792-7134311619d8.png)

## Contact

If you want to contact me you can reach me at Mariano_Desivo@hotmail.com.

## License

This project uses the following license: [MIT License](https://github.com/MarianoDesivo/Rc5Send/blob/main/LICENSE).
