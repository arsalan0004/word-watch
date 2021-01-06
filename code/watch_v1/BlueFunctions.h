#include "MCP2380.h"

#define BLUE1 0b11111110
#define BLUE2 0b11111101
#define BLUE3 0b11111011
#define BLUE4 0b11110111
#define BLUE5 0b11101111

#define PINK1 4 //PD4
#define PINK2 0 //PD0
#define PINK3 2 //PD2
#define PINK4 1 //PD1

bool five;

void resetPink(){
  pinMode(PINK1, INPUT);
  pinMode(PINK2, INPUT);
  pinMode(PINK3, INPUT);
  pinMode(PINK4, INPUT);
}

void twentyFive(int i){
  if(five == true){
    i = i%5;
    switch(i){
    case 0:
      resetPink();
      pinMode(PINK3, OUTPUT);
      pinMode(PINK2, OUTPUT);
      digitalWrite(PINK2, HIGH);
      digitalWrite(PINK3, LOW);
      break;
    case 1:
      resetPink();
      pinMode(PINK3, OUTPUT);
      pinMode(PINK2, OUTPUT);
      digitalWrite(PINK3, HIGH);
      digitalWrite(PINK2, LOW);
      break;
      
    case 2:
      resetPink();
      resetMCP23008(0b11110011);
      glowMCP23008(0b00001000); 
      //en
      break;

    case 3:
      glowMCP23008(0b00000000);
      resetMCP23008(0b11111001);
      glowMCP23008(0b00000100);
      //T1,y
      //en
      break;

    case 4:
      glowMCP23008(0b00000000);
      resetMCP23008(0b11100111);
      glowMCP23008(0b00001000);
      //T2, W
      break;
    }
    return;}
  
  
  else{
  i = i%3;
  switch(i){
    case 0:
    resetMCP23008(0b11110011);
    glowMCP23008(0b00001000); 
    //en
    break;

    case 1:
    glowMCP23008(0b00000000);
    resetMCP23008(0b11111001);
    glowMCP23008(0b00000100);
    //T1,y
    //en
    break;

    case 2:
    glowMCP23008(0b00000000);
    resetMCP23008(0b11100111);
    glowMCP23008(0b00001000);
    //T2, W
    break;
  }
  return;
}
}




void half(int i){
  i = i%2;
  switch(i){
    case 0:
      resetMCP23008(0b11111100);
      glowMCP23008(0b00000001);
      break;
    case 1:
      glowMCP23008(0b00000010);
      break;
  }

}

void fiveHour(int i){
  i = i%2;
  switch(i){
    case 0:
      resetMCP23008(0b11111010);
      glowMCP23008(0b00000001); 
      break;
   case 1:
      glowMCP23008(0b00000100);
      break;  
  }
  

}
void quarter(int i){
  i = i%4;
  switch(i){
    case 0:
      resetMCP23008(0b11110011);
      glowMCP23008(0b00000100);
      break;
    case 1:
      resetMCP23008(0b11110101);
      glowMCP23008(0b00000010);
      break;
    case 2:
      resetMCP23008(0b11110101);
      glowMCP23008(0b00001000);
      break;
    case 3: 
      glowMCP23008(0b00000000); //fix ten bug :)//in the code thtat glows 'TR' we have blue4 set to an output, and it's high. In the code after this line 
      resetMCP23008(0b11110110);//we have blue4 set to an output, and it's still high while blue1 is low. This causes TN of TEN to glow. To avoid this, 
      glowMCP23008(0b00000001);//we set all outputs to low, and then reset the io expander, and then configure the outputs how we want. 
      break;
  
}
}

void tenMinutes(int i){
  i = i%3;
  switch(i){
    case 0:
      resetMCP23008(0b11110110);
      glowMCP23008(0b00001000);
      break;
      //T-N
    case 1: 
      glowMCP23008(0b11111111);
      resetMCP23008(0b11100111);
      break;
    case 2:
      glowMCP23008(0b00010000);
      break;
    //E
}
}
