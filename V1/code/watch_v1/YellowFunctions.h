

#define GREEN1 9
#define GREEN2 14
#define GREEN3 15
#define GREEN4 10


/////////////*************************YELLOW FUNCTIONS*******************************************/////
void tenHour(int i){
  i = i%2;
  switch(i){
    case 0:
      resetMCP23008(0b00000000);
      resetMCP23008(0b01011111);
      glowMCP23008(0b10000000);
      break;
    case 1:
      resetGreen();
      pinMode(GREEN2, OUTPUT);
      pinMode(GREEN1, OUTPUT);
      digitalWrite(GREEN2, HIGH);
      digitalWrite(GREEN1, LOW);
      
  }
}


void seven(int i){
  int x = i%3;

  switch(x){
    case 1:
    resetMCP23008(0b10011111);
    glowMCP23008(0b01000000);
    

    case 2:
    glowMCP23008(0b00100000);
    

    case 3:
    resetMCP23008(0b01011111);
    glowMCP23008(0b00100000);
    
  }
}

void nine(int i){
  i = i%2;
  switch(i){
    case 0:
      resetMCP23008(0b00111111);
       glowMCP23008(0b10000000);
      break;
      
    case 1:
       glowMCP23008(0b01000000);
  }
}
