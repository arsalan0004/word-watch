/*
Title: Indicator_Functions
Creator: Arsalan Syed
libraries required: Wire.c 
Last Update: Jan 23th, 2021, by Arsalan Syed




Description:
This file is part of the Word-Watch V2 project.
This file contains all the functions which are called to glow the letters associated with words that indicate which
side of the clock the time is on. For example, functions such as 'past' and 'to' to indicate, for example, that it 
is 'half past four', or '25 to four'

This file also contains the 'it_is' function, which is turned on everytime the clock is checked.

All the LEDs associated with spelling out minutes are controlled by the ATMEGA328p-au. 

*/
#ifndef  MIN3
  #define MIN3 1//PD1
#endif

#ifndef  MIN6
  #define MIN6 5//PD5
#endif

#define INDICATOR1 14// PC0
#define INDICATOR2 15// PC1
#define INDICATOR3 16// PC2

#define IT_IS1 21// PD7
#define IT_IS2 20// PD6





void set_IndicatorPins_INPUT(){
  pinMode(INDICATOR1,INPUT);
  pinMode(INDICATOR2,INPUT);
  pinMode(INDICATOR3,INPUT);

  pinMode(IT_IS1,INPUT);
  pinMode(IT_IS2,INPUT);
}

void past(int i){
  //includes pins 'Indicator 1, 'indicator2' and 'indicator3'

  i = i%2;
  switch(i){
    case 0:
      pinMode(INDICATOR1, INPUT); pinMode(INDICATOR2,OUTPUT); pinMode(INDICATOR3,OUTPUT);
      digitalWrite(INDICATOR2, HIGH); digitalWrite(INDICATOR3, LOW);  //glows 'S' and 'T'
      break;
      
    case 1:
      pinMode(INDICATOR2,INPUT); pinMode(INDICATOR1,OUTPUT);
      digitalWrite(INDICATOR3, HIGH); digitalWrite(INDICATOR1, LOW); //glows 'P' and 'A'
      break;
  }
}

void to(int i){
  //does not use int i, but is included anyways because, in 'main' a pointer will point to either 
  //'past(int i)' or 'to', and so, for that pointer to be able to hold both this function or 'past' it must 
  //also include 'int i' as a parameter.

  //involves pins 'Indicator 1' and 'indicator2'
  pinMode(INDICATOR1,OUTPUT); pinMode(INDICATOR3, OUTPUT);
  digitalWrite(INDICATOR1, HIGH); digitalWrite(INDICATOR3, LOW); // glows 'T' and 'O'
}

void oclock(int i){
  //uses pins 'min3', 'min6' and 'indicator1' and 'indicator2'
  i = i%3;
  switch(i){
    case 0:
      pinMode(MIN3,INPUT); pinMode(MIN6, INPUT); pinMode(INDICATOR1,OUTPUT); pinMode(INDICATOR2, OUTPUT);
      digitalWrite(INDICATOR1, HIGH); digitalWrite(INDICATOR2, LOW); //glows '1st O' and '1st C'
      
    case 1:
      digitalWrite(INDICATOR2, HIGH); digitalWrite(INDICATOR1, LOW); //glows '2nd O' and 'L'
      break;
      
    case 2:
    pinMode(INDICATOR1,INPUT); pinMode(INDICATOR2, INPUT); pinMode(MIN3,OUTPUT); pinMode(MIN6, OUTPUT); 
    digitalWrite(MIN6, HIGH); digitalWrite(MIN3, LOW); //glows '2nd C' and 'K'
  }
}
