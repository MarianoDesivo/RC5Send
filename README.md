# Rc5Send

I made this because other libraries would not work on my Phillip devices.

Using the Timer1 registers, from Atmega328P microprocessor, Arduino sends a PWM signal to build the RC5 messages.

## Prerequisites

* Arduino UNO (haven't tested in other devices but should work)
* Infrared LED
* 47-220ohm resistor

## Specifications

I followed the specifications below. Burst is set at 36kHz with a Duty Cycle of 28%.

![image](https://user-images.githubusercontent.com/79780807/112241629-66223e00-8c29-11eb-83ef-01184de6e994.png)


## Installing Rc5Send

To install Rc5Send, follow these steps:

* Download (Rc5Send as .zip)[https://github.com/MarianoDesivo/RC5Send/archive/refs/heads/main.zip]
* Extract the RC5Send folder
* Move it to your library folder. For example "C:\Users\MARIANO\Documents\Arduino\libraries"

## Using Rc5Send

* J


### Other functions

* There is a watched videos counter. If it reaches 300 it will reset the watched list.
```python
    if contador > 300: #If we have watched more than 300 videos 
      f = open('CapitulosVistos.txt', 'w')    #Reset the list to start again

```
* There is a 10% chance you get a repeated video
```python
    if random.randint(1,10) == 1: #There is a 10% chance to watch a video you have already seen
```

## Contact

If you want to contact me you can reach me at Mariano_Desivo@hotmail.com.

## License

This project uses the following license: [MIT License](https://github.com/MarianoDesivo/Rc5Send/blob/main/LICENSE).
