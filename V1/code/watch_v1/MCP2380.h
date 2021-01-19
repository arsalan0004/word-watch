#include "Wire.h"

#define PINK1 4 //PD4
#define PINK2 0 //PD0
#define PINK3 2 //PD2
#define PINK4 1 //PD1

void glowMCP23008(byte name){
  
  Wire.beginTransmission(0x20); //addr
  Wire.write(0x09);   //access addr for GPIO access
  Wire.write(name);   //setting voltage. 1 = high, 0 = low 
  Wire.endTransmission();
}

void resetMCP23008(byte outputs){
  glowMCP23008(0b00000000); //set all pins low
  
  Wire.beginTransmission(0x20); //mcp23008 i2c address
  Wire.write(0x00);   //internal register for IO dir 
  Wire.write(outputs);   // set all pins as input except those specified by mask
  Wire.endTransmission();

  
}
