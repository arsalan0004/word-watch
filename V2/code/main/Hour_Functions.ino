/*
Title: Hour_Functions
Creator: Arsalan Syed
libraries required: Wire.c 
Last Update: Jan 19th, 2021, by Arsalan Syed

Description:
This file is part of the Word-Watch V2 project.
This file contains all the functions which are called to glow the letters associated with hours.
All the LEDs associated with spelling out hours are controlled by the MCP23008 I/O expander, which is controlled through I2C. 

*/

#include "Wire.h"

#define MCP23008_ADDRESS 0x20
#define MCP23008_GPIO_REG 0x09
#define MCDP23008_IODIR_REG 0x00

#define HOUR1 0b10000000 //pin 7
#define HOUR2 0b01000000 //pin 6
#define HOUR3 0b00001000 //pin 3
#define HOUR4 0b00010000 //pin 4
#define HOUR5 0b00100000 //pin 5
#define HOUR6 0b00000100 //pin 2     
#define HOUR7 0b00000010 //pin 1
#define HOUR8 0b00000001 //pin 0


void MCP23008_setPinAsOutput(byte pin1 byte pin2){
  //sets pins specified with a '1' as output, and those specified with a '0' as input 
  //example: byte pins = 0b00000001 sets pins 1-7 to input, and pin 0 as output

 
  
  pins = ~(pin1 | pin2);
  //inverts the pins because the MCP23008 harware actually requires that output pins be specified by '0'
  //and input pins specified by  '1'
  //our method uses the inverse because it allows us to be consistant with our methods to 
  //set pins as output and then set them as High.
  //example of our methodology : MCP23008_setPinAsOutput(HOUR1) sets the pin associated with HOUR1 as output 
  //                             MCP23008_set(HOUR1) sets the pin associated with HOUR1 high.  

  //wheras if we did not invert 'byte pins' we would have to do this:
  //example of our methodology : MCP23008_setPinAsOutput(~HOUR1) sets the pin associated with HOUR1 as output 
  //                             MCP23008_set(HOUR1) sets the pin associated with HOUR1 high.  

  
  Wire.beginTransmission(MCP23008_ADDRESS);
  Wire.write(MCP23008_IODIR_REG);   
  Wire.write(pins);
  Wire.endTransmission();
  
}

void MCP23008_Reset(){
  //sets all the MCP23008 pins low
  MCP23008_set(0);
}


void MCP23008_set(byte input){
  //sets the MCP23008 pins specificed by the byte inputted.
  //example: input byte: 00000001 sets pin 1, and clears pins 8-2.

  Wire.beginTransmission(MCP23008_ADDRESS);
  Wire.write(MCDP23008_GPIO_REG);              //access address for GPIO access
  Wire.write(input);                           //setting voltage. 1 = high, 0 = low 
  Wire.endTransmission();
  
}


void one_Hour(int i){
  //involves hour 1 and hour 5 
  MCP23008_set(HOUR1);

  
}
