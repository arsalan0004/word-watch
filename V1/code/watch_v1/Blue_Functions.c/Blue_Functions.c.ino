
void twenty(int i){
  int x = i%3;
  switch(x){
    case 1:
    resetMCP23008(0b11110011);
    glowMCP23008(0b00001000);
    delay(FLICKER_DELAY); 
    //en
    break;

    case 2:
    glowMCP23008(0b00000000);
    resetMCP23008(0b11111001);
    glowMCP23008(0b00000100);
    delay(FLICKER_DELAY); 
    //T1,y
    //en
    break;

    case 3:
    glowMCP23008(0b00000000);
    resetMCP23008(0b11100111);
    glowMCP23008(0b00001000);
    delay(FLICKER_DELAY);
    //T2, W
    break;
  }
  resetMCP23008(0b00000000);
}




void half(int i){
  resetMCP23008(0b11111100);
  glowMCP23008(0b00000001);
  delay(FLICKER_DELAY);
  glowMCP23008(0b00000010);
  delay(FLICKER_DELAY);

}

void fiveHour(int i){
  resetMCP23008(0b11111010);
  glowMCP23008(0b00000001); 
  delay(FLICKER_DELAY); 
  glowMCP23008(0b00000100);
  delay(FLICKER_DELAY); 

}
void quarter(int i){
  
  resetMCP23008(0b11110011);
   glowMCP23008(0b00000100);
  delay(FLICKER_DELAY); 
  //qu or en? (twnety)
  
  resetMCP23008(0b11110101);
   glowMCP23008(0b00000010);
  delay(FLICKER_DELAY); 
  //ER
  
  resetMCP23008(0b11110101);
   glowMCP23008(0b00001000);
   delay(FLICKER_DELAY); 
  //TR

  glowMCP23008(0b00000000); //fix ten bug :)//in the code thtat glows 'TR' we have blue4 set to an output, and it's high. In the code after this line 
                            //we have blue4 set to an output, and it's still high while blue1 is low. This causes TN of TEN to glow. To avoid this, 
                            //we set all outputs to low, and then reset the io expander, and then configure the outputs how we want. 
  resetMCP23008(0b11110110);
  
  glowMCP23008(0b00000001);
  delay(FLICKER_DELAY); 
  //A

  
}


void tenMinutes(int i){
  resetMCP23008(0b11110110);
  glowMCP23008(0b00001000);
  delay(FLICKER_DELAY);
  //T-N
  
  glowMCP23008(0b11111111);
  resetMCP23008(0b11100111);
  //delay(FLICKER_DELAY);
  glowMCP23008(0b00010000);
  delay(FLICKER_DELAY);
  //E
}
