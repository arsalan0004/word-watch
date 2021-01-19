
//3's orbit needs to be filled, otherwise the resistance is too high
//seven after eleven doesn't work for some reason when we test all LEDS at once. 
//maximum of 10 LEDS at once. 
//should move oclock from 'it is' so that I'll have no problem doing it is X oclock // fix the whole red function lol 
//next time, have the letters distributed over networks ex. quarter = qu in red, ar in blue, ter in yellow so you can glow them at the same time!!
//next time, put all the minutes in one net and all the hours in another so they can be turned on at the same time//mostly five needs to be changed.
//twentyfive - the five lights up less bright than the twenty



#include "GreenFunctions.h"
#include "RedFunctions.h"
#include "BlueFunctions.h"
#include "YellowFunctions.h"
#include "PinkFunctions.h"
#include "PCF8523.h"


#include "RTClib.h"
#include "Wire.h"


#define BUTTON 4
#define INT1_PIN 3

#define GLOW_FRAMES 10000




int getAddrOfHourFunction(int hour);
int getAddrOfMinFunction(int rm);
void doNothingFunction(int i); 
int roundMin(int m);
bool afterThirty(int rm);
void showTime(int h, int m);
bool beforeThirty(int rm);
void goToSleep();
void digitalInterrupt();
void resetAllLEDS();


byte bcdToDec(byte value);
byte decToBcd(byte value);







void setup() {
  
  Wire.begin();
  setPCF8523(2,15);
  attachInterrupt(digitalPinToInterrupt(3), digitalInterrupt, FALLING); //interrupt for waking up
  goToSleep();
  
  
  
  }


void loop() {
  

  readPCF8523(); 
  //fiveMinutes(0);
  showTime(currentHours, currentMinutes);
  //attachInterrupt(INT1_PIN, digitalInterrupt, FALLING);
  goToSleep();
   
 
}

void digitalInterrupt(){
  
  //wakes up the arduino for one cycle through loop?
  //detachInterrupt(3);
  //readPCF8523();
  //showTime(currentHours, currentMinutes);
  
}

void goToSleep(){
  
  //set every pin as input (except sda, sla, 
  for(int ii = 0; ii< 20; ii++){
    if(ii == 18 || ii == 19){
      //SDA and SLA lines should not be set as input
      continue;
    }else{
      pinMode(ii, INPUT);
    }
    }

  //turn off ADC
  ADCSRA &= ~(1 <<7);
  
  //enable sleep
  SMCR |= (1<<2); //power down mode
  SMCR |= 1; //enable sleep
  
  //turn off BOD
  MCUCR != (3 <<5);
  MCUCR = (MCUCR & ~(1 << 5)) | (1 <<6);
  __asm__ __volatile__("sleep");

}



void showTime(int h, int m){
  //pointers to minutes and hours functions 
  void (*min_ptr)(int);
  void (*hour_ptr)(int);
  bool enTo;
  bool enPast;
  bool enOclock;
  

  //process hours
  int addr = getAddrOfHourFunction(h);
  hour_ptr = addr;
  
  //process minutes
  int rm = roundMin(m); //rm = rounded minute 
  min_ptr = getAddrOfMinFunction(rm);
  

  //decide if we will glow 'to' or 'past'
  enPast = beforeThirty(rm);
  enTo = afterThirty(rm);

  //decide if we should glow 'Oclock'
  if(rm == 0){
     enOclock = true;
     enPast = false;
     enTo = false;
  }
  else{
    enOclock = false;
  }
  
  //glow the time
  //three options for now
  if(rm == 0){
    for(int i =0; i<GLOW_FRAMES; i++){
    it_is_to_past_oclock(i,enTo,enPast,enOclock);
    (*hour_ptr)(i);
    
    }
    resetAllLEDS();
    return;
  }

  if( min_ptr == &five || (min_ptr == &twentyFive && five == true)){
      for(int i =0; i<GLOW_FRAMES; i++){
      it_is_to_past_oclock(i,enTo,enPast,enOclock);
      (*hour_ptr)(i);
      resetPink();
      (*min_ptr)(i);
      }
      resetAllLEDS();
      return;
  }       
  else{
    for(int i =0; i<GLOW_FRAMES; i++){
      it_is_to_past_oclock(i,enTo,enPast,enOclock);
      (*hour_ptr)(i);
      (*min_ptr)(i);
    
      
    }
    return
    resetAllLEDS();
}
}

     

  

  //set everything as input so that there won't be any problems in the next cycle
  
  
     

void resetAllLEDS(){
  resetRed();
  resetGreen();
  resetPink();
  resetMCP23008(0b00000000);
}
  

int getAddrOfMinFunction(int m){
  int addrOfMinFunction;
  m = -abs(m-30) + 30 ;
  switch(m){
    case 0:
      addrOfMinFunction = &Oclock;
    case 5:
      addrOfMinFunction = &fiveMinutes;
      break;
    case 10:
      addrOfMinFunction = &tenMinutes;
      break;
    case 15:
      addrOfMinFunction = &quarter;
      break;
    case 20:
      addrOfMinFunction = &twentyFive;
      five = false;
      break;
    case 25: //special case because the pointer needs to point to twenty and five
      addrOfMinFunction = &twentyFive;
      five = true;
      break;
    case 30:
      addrOfMinFunction = &half;
      break;
  }
  return addrOfMinFunction;
}

int getAddrOfHourFunction(int hour){
  int addrOfHourFunction;
  
  switch(hour){
    case 1:
      addrOfHourFunction = &one;
      break;
    case 2:
      addrOfHourFunction = &two;
      break;
    case 3: 
      addrOfHourFunction = &three;
      break;
    case 4:
      addrOfHourFunction = &four;
      break;
    case 5:
      addrOfHourFunction = &fiveHour;
      break;
    case 6: 
      addrOfHourFunction = &six;
      break;
    case 7:
      addrOfHourFunction = &seven;
      break;
    case 8:
      addrOfHourFunction = &eight;
      break;
    case 9:
      addrOfHourFunction = &nine;
      break;
    case 10:
      addrOfHourFunction = &tenHour;
      break;
    case 11:
      addrOfHourFunction = &eleven;
      break;
    case 12:
      addrOfHourFunction = &twelve;
      break;
  }
  return addrOfHourFunction;
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

bool afterThirty(int rm){
    if(rm == 0){
      return false;
    }
    
    if(rm > 30){
      return true;
    }
    else{
       return false;
        }
}

bool beforeThirty(int rm){
  if(rm == 0){
      return false;
    }
    
    if(rm <= 30){
      return true;
    }
    else{
       return false;
        }
}
