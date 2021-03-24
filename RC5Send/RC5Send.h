/*
  RC5Send.h - Library for sending RC5 code.
  Created by Mariano J. Desivo, March 18, 2021.
  Released into the public domain.
*/

#ifndef RC5Send_h
#define RC5Send_h

#include "Arduino.h"

class Rc5
{
  public:
    Rc5(void);	
    void Begin(void);
    int Send(int addr, int comm);
    void print(char string[]);    
  private:
    int _pin;
};

#endif