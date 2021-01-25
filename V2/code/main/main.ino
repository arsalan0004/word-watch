/*
Title: main
Creator: Arsalan Syed
libraries required: Wire.c 
Last Update: Jan 23st, 2021, by Arsalan Syed

Description:
This is the main script of the Word_watch project V2. The file contains functions which are monitor if a button has 
been clicked, which would indicate if the watch should turn on and tell the time. When the button is clicked the watch
will turn for a brief, specified time, and then turn off again. By 'turning off' it is meant that the ATMEGA328p-au
will go into deep sleep mode to conserve energy. This state should only draw 19 uA, so the ATMEGA chip should be able
to run for years while being in sleep. There will also be functions included which will allow the user to change the time.

*/
#include "Hour_Functions.h" 
#include "Minute_Functions.h"
#include "Indicator_Functions.h"
#include "PDF8523_RTC.h"

#define GLOW_FRAMES  5000


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


void showTime(int h, int m){
  //pointers to minutes and hours functions 
  void (*min_ptr)(int);
  void (*hour_ptr)(int);
  void (*indicator_ptr)(int);

  //process hours
  int addr = getAddrOfHourFunction(h);
  hour_ptr = addr;

  //process minutes
  int rm = roundMin(m); //rm = rounded minute 
  min_ptr = getAddrOfMinFunction(rm);

  //decide if 'past' 'to' or 'oclock' should be glowed
  if(rm == 0){
    indicator_ptr = oclock();
  }
  if(rm <30){
    indicator_ptr = to();
  }
  if(rum >=30){
    indicator_ptr = past();
  }
    
  //now that we have all the information we need, we can glow the time 

  for(int i = 0; i<GLOW_FRAMES; i++){
    (*hour_ptr)(i);
    (*min_ptr)(i);
    (*indicator_ptr)(i);
  }
     set_HourPins_INPUT();
     set_MinPins_INPUT();
     set_IndicatorPins_INPUT();
  
 
  
}

void goToSleep(){
  
  //set every pin as input (except sda, sla)
  for(int ii = 0; ii< 20; ii++){
    if(ii == 18 || ii == 19){
      //SDA and SLA lines should not be set as input
      continue;
    }else{
      pinMode(ii, INPUT);
    }
    }

  //turn off ADC
  ADCSRA &= ~(1 <<7); //write a zero to the ADC enable bit in the ADC and Status Register A byte
  
  //enable sleep
  SMCR |= (1<<2); //power down mode
  SMCR |= 1; //enable sleep
  
  //turn off BOD
  MCUCR != (3 <<5); //set both the BODS and BODSE bits in the MCU control register
  MCUCR = (MCUCR & ~(1 << 5)) | (1 <<6); //set the BODS bit and clear the BODSE bit at the same time 
  __asm__ __volatile__("sleep");

}


int roundMin(int m){
  //rounds minutes to the closest 5 minute denomination
  int rm;
  int fractionOfFive = m%5;
  if(fractionOfFive >=3){
    rm = m - (m%5) + 5;
  }else{
    rm = m - (m%5);
  }

  if(rm >55){
    rm = 0;
  }
  return rm;
}
