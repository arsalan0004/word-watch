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




void MCP23008_reset(){
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
}
