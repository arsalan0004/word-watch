/*watch project script*/
/*lights up LEDs on the circuit board when the button is clicked*/
/*designed by: Arsalan Syed*/
/*Last updated: Feb 14 2020*/


#define NUM_OF_PINS

#define YELLOW1
#define YELLOW2
#define YELLOW3

#define RED1
#define RED2
#define RED3
#define RED4

#define GREEN1
#define GREEN2
#define GREEN3
#define GREEN4

#define PINK1
#define PINK2
#define PINK3
#define PINK4

#define BLUE1
#define BLUE2
#define BLUE3
#define BLUE4
#define BLUE5

#define BUTTONPIN

#define DELAY_BETWEEN_SEGMENTS

int currentHour;
int currentMinutes;
static int currentWordSegment;   //which two or three letters of a word should be illuminated
const int delayBetweenSegments; //related to PWM function
const int blinkDelay;           //while changing the time, how much delay there should be between each blink
const float displayTime;
bool buttonClicked;



bool glowMinutes;
bool glowWords;
bool glowHours;

bool recentTickUp;



void setup() {
  /*initialize time*/
  currentHour = 0;
  currentMinutes = 0;
  currentWordSegment = 0;

  /*initialize button pin*/
  pinMode(BUTTONPIN, INPUT);
  buttonClicked = false;
  recentTickUp = false;
  
}

void loop() {
  
}
  //updates time ever 5 seconds 
  UpdateTime();
  
  //checks if button is clicked
  ButtonMoniter();
  
  
}

void UpdateTime(){

  /*300000 milliseconds == 5 minutes*/
  if ((abs((millis()%300000 < 50) and (not(recentTickUp)){
    if((currentMinutes == 55)){
      currentHour = (currentHour + 1)%12;
      currentMinutes = 0;
      
     else{
      currentMinutes +=5; 
     }
    }
    recentTickUp = true;
    tickUpTime = millis();
   }
  if((recentTickUp) and ((millis() - tickUpTime) > 200)){
    recentTickUp = false;
    }
  }

void ButtonMoniter(){
  //checks to see if the button was clicked 
  //clicked: show time by looping glowtime so that all the segments are looped over so quick that 
  //we don't notice them flickering. And also we want to make sure that the lights are on long enough
  //for the user to see them
  //held down:manually change time 

  
  if(digitalRead(BUTTONPIN) ==  HIGH && buttonClicked == false){
    float timeButtonClicked = millis();
    buttonClicked = true;
  }
  if(digitalRead(BUTTONPIN) == LOW && buttonClicked == true){
    float timeButtonUnclicked == millis();
    buttonClicked = false;
  
    float pressDownTime = timeButtonUnclicked - timeButtonClicked;
    
    if(pressDownTime > 1000){
      ButtonHeldDown();
    }else 
    {
      ButtonClicked();
    }
  }
  
}

void ButtonClicked(){
  //show time
  float timeButtonClicked = millis();
  while((timeButtonClicked + displayTime) > millis()){
    GlowTime(true, true, true);
    delay(delayBetweenSegments);
    currentWordSegment += 1;
    resetPins();
  }
  /*reset word segment number after each time the watch shows us the time*/
  currentWordSegment = 0;
}

//current point
void ButtonHeldDown(){

  
  /*
  array of pointers 
  each time the button is clicked, we iterate through this array 
  when we reach the end of the array, we set @exit to true, and exit this loop
  */
  int *ArrayOfTimePointers[2]{
    {*MinutesPointer},{*hoursPointer}
  }
  minutesPointer = &currentMinutes;
  hoursPinter = &currentHour;

  bool @exit = false;
  bool buttonClicked = false;
  int *currentTime = &currentMinutes;

  /*change minutes*/
  while(@exit == false){
    glowTime(false,false,true);
    delay(delayBetweenSegments);
    currentWordSegment += 1;
    resetPins();

    if(digitalRead(BUTTONPIN) == HIGH && buttonClicked == false){
      float buttonClickTime = millis();
      buttonClicked == true;
    if(digitalRead(BUTTONPIN) == LOW and buttonClicked == true){
      float buttonUnclickedTime = millis();
      if(buttonUnclickedTime - buttonClickTime > 1000){
        
      }
      else{
        *currentTime += 1;
      }
    }
    
    }
  whi
    
  }

  //current hour should blink 
  
  //if button clicked, itterate through hours 
  //if button heldDown, allow to iterate through minutes with click 
  //if button heldDown, exit time changing mode
}


void GlowTime(bool glowWords, bool glowMinutes, bool GlowHours){

//if button is clicked 

  GlowIt();
  GlowIs();

//Minutes
if(glowMinutes == true){
  if(currentMinutes == 5 || currentMinutes == 55){
    Glow_FiveMinutes(currentWordSegment);
  }
  if(currentMinutes == 10 || currentMinutes == 50){
    Glow_TenMinutes(currentWordSegment);
  }
  if(currentMinutes == 15 || currentMinutes == 45){
    Glow_Quarter(currentWordSegment);
  }
  if(currentMinutes == 20 || currentMinutes == 40){
    Glow_Twenty(currentWordSegment);
  }  
  if(currentMinutes == 25 || currentMinutes == 45){
    Glow_Twenty(currentWordSegment);
    Glow_Five(currentWordSegment);
  }
  if(currentMinutes == 30){
    Glow_Half(currentWordSegment);
}
}

//glow Words 
  if(glowWords == true){
    if(currentMinutes > 30){
      Glow_To();
    else{
      Glow_Past(currentWordSegment);
    }
    if(currentMinutes == 0){
      Glow_OClock(currentWordSegment);
    }
   }
  }
   
 
//hours 
  if(glowHours == true){
    if(currentHour == 1){
      Glow_One(currentWordSegment);
    }
    if(currentHour == 2){
      Glow_Two(currentWordSegment);
    }
    if(currentHour == 3){
      Glow_Three(currentWordSegment);
     }
    if(currentHour == 4){
      Glow_Four(currentWordSegment);
    }
    if(currentHour == 5){
      Glow_Five(currentWordSegment);
    }
    if(currentHour == 6){
      Glow_Six(currentWordSegment);
    }
    if(currentHour == 7){
      Glow_Seven(currentWordSegment);
    }
    if(currentHour == 8){
      Glow_Eight(currentWordSegment);
    }
    if(currentHour == 9){
      Glow_Nine(currentWordSegment);
    }
    if(currentHour == 10){
      Glow_Ten(currentWordSegment);
    }
    if(currentHour == 11){
      Glow_Eleven(currentWordSegment);
    }
    if(currentHour == 12){
      Glow_Twelve(currentWordSegment);
    }
    }
}



void Glow_It(){
  pinMode(RED2, OUTPUT);
  pinMode(RED1, OUTPUT);
  
  digitalWrite(RED2, HIGH);
  digitalWrite(RED1, LOW);
}

void Glow_Is(){
  pinMode(RED2, OUTPUT);
  pinMode(RED1, OUTPUT);
  
  digitalWrite(RED3, HIGH);
  digitalWrite(RED2, LOW);
}

void Glow_To(){
  pinMode(RED2, OUTPUT);
  pinMode(RED1, OUTPUT);
  
  digitalWrite(RED1, HIGH);
  digitalWrite(RED2, LOW);
}

void Glow_Half(int segment){
  segment = segment%2;
  
  pinMode(BLUE1, OUTPUT);
  pinMode(BLUE2, OUTPUT);
  switch(segment){
    
    case 0:
    digitalWrite(BLUE1, HIGH);
    digitalWrite(BLUE2, LOW);
    break;

    Case 1:
    digitalWrite(BLUE2, HIGH);
    digitalWrite(BLUE1, LOW);
    break;
  }
  
}
  
}

void Glow_Twenty(int segment){
  segment = segment%3;
  
  switch(segment){
    case 0: 
    pinMode(BLUE3, OUTPUT);
    pinMode(BLUE4, OUTPUT);
    digitalWrite(BLUE3, HIGH); //T2-Y
    digitalWrite(BLUE4, LOW); //T2-Y
    break;

    case 1: 
    pinMode(BLUE3, OUTPUT);
    pinMode(BLUE2, OUTPUT);
    digitalWrite(BLUE3, HIGH); //W-E
    digitalWrite(BLUE2, LOW); //W-E
    break;

    case 2:
    pinMode(BLUE3, OUTPUT);
    pinMode(BLUE2, OUTPUT);
    digitalWrite(BLUE2, HIGH); //N-T
    digitalWrite(BLUE3, LOW); //N-T
    break;
  }
}


void Glow_Quarter(){
    segment = segment%4;
    switch(segment){
    
    case 0:
    pinMode(BLUE4, OUTPUT);
    pinMode(BLUE2, OUTPUT);
    digitalWrite(BLUE2, HIGH); //R-T-R2
    digitalWrite(BLUE4, LOW); //R-T-R2
    break;

    Case 1:
    pinMode(BLUE4, OUTPUT);
    pinMode(BLUE2, OUTPUT);
    digitalWrite(BLUE4, HIGH); //E
    digitalWrite(BLUE2, LOW); //E
    break;

    case 2: 
    pinMode(BLUE4, OUTPUT);
    pinMode(BLUE3, OUTPUT);
    digitalWrite(BLUE4, HIGH); //Q-U
    digitalWrite(BLUE3, LOW); //Q-U

    case 3:
    pinMode(BLUE5, OUTPUT);
    pinMode(BLUE4, OUTPUT);
    digitalWrite(BLUE5, HIGH); //A- (T)EN
    digitalWrite(BLUE4, LOW); //A 
    
    }

  
}

//need to flip this 
void Glow_TenMinutes(int segment){
  segment = segment%2;
  switch(segment){
    
  case 0: 
  pinMode(BLUE4, OUTPUT);
  pinMode(BLUE5, OUTPUT);
  digitalWrite(BLUE4, HIGH); //T
  digitalWrite(BLUE5, LOW); //T

  case 1: 
  pinMode(BLUE5, OUTPUT);
  pinMode(BLUE2, OUTPUT);
  digitalWrite(BLUE2, HIGH); //E-N
  digitalWrite(BLUE5, LOW); //E-N
  
    
  }
}


void Glow_FiveMinutes(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(BLUE1, OUTPUT);
    pinMode(BLUE3, OUTPUT);
    digitalWrite(BLUE1, HIGH); //I-E
    digitalWrite(BLUE3, LOW); //I-E

    case 1: 
    pinMode(BLUE1, OUTPUT);
    pinMode(BLUE3, OUTPUT);
    digitalWrite(BLUE3, HIGH); //F-V
    digitalWrite(BLUE1, LOW); //F-V
  }

}
  

void Glow_Twelve(int segment){
  segment = segment%3;
  switch(segment){
    case 0:
    pinMode(PINK1, OUTPUT);
    pinMode(PINK2, OUTPUT);
    digitalWrite(PINK2, HIGH);//T-W
    digitalWrite(PINK1, LOW);//T-W
    break;

    case 1:
    pinMode(PINK1, OUTPUT);
    pinMode(PINK2, OUTPUT);
    digitalWrite(PINK1, HIGH);//E-L
    digitalWrite(PINK2, LOW);//E-L
    break;

    case 2:
    pinMode(PINK3, OUTPUT);
    pinMode(PINK2, OUTPUT);
    digitalWrite(PINK3, HIGH);//V-E(2)
    digitalWrite(PINK2, LOW);//V-E(2)
    break;
  }
  
}

void Glow_Eleven(int segment){
    
  segment = segment%3;
  switch(segment){
    case 0:
    pinMode(PINK1, OUTPUT);
    pinMode(PINK4, OUTPUT);
    digitalWrite(PINK4, HIGH);//E-L
    digitalWrite(PINK1, LOW);//E-L
    break;

    case 1:
    pinMode(PINK4, OUTPUT);
    pinMode(PINK3, OUTPUT);
    digitalWrite(PINK4, HIGH);//E2-V
    digitalWrite(PINK3, LOW);//E2-V
    break;

    case 2:
    pinMode(PINK3, OUTPUT);
    pinMode(PINK2, OUTPUT);
    digitalWrite(PINK2, HIGH);//E3-N
    digitalWrite(PINK3, LOW);//E3-N
    break;
  }
  
}

void Glow_Ten(){
  pinMode(YELLOW1, OUTPUT);
  pinMode(YELLOW3, OUTPUT);
  digitalWrite(YELLOW1, HIGH);//T-E-N
  digitalWrite(YELLOW3, LOW);//T-E-N
  
}

void Glow_Nine(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(YELLOW2, OUTPUT);
    pinMode(YELLOW3, OUTPUT);
    digitalWrite(YELLOW3, HIGH);//E-I
    digitalWrite(YELLOW2, LOW);//E-I
    break;

    case 1:
    pinMode(YELLOW2, OUTPUT);
    pinMode(YELLOW3, OUTPUT);
    digitalWrite(YELLOW2, HIGH);//N-N
    digitalWrite(YELLOW3, LOW);//N-N
    break;

}

void Glow_Eight(int segment){
  segment = segment%3;
  switch(segment){
    case 0:
     pinMode(PINK1, OUTPUT);
     pinMode(PINK4, OUTPUT);
     digitalWrite(PINK1, HIGH); //E
     digitalWrite(PINK4, LOW); //E
     break;

    case 1: 
    pinMode(PINK1, OUTPUT);
    pinMode(PINK3, OUTPUT);
    digitalWrite(PINK1, HIGH); //I-G
    digitalWrite(PINK3, LOW); //I-G
    break;

    case 2:
    pinMode(PINK3, OUTPUT);
    pinMode(PINK4, OUTPUT);
    digitalWrite(PINK3, HIGH); //H-T
    digitalWrite(PINK4, LOW); //H-T
    break;
  }
  
}

void Glow_Seven(int segment){
  segment = segment%3;
  switch(segment){
    case 0:
    pinMode(YELLOW2, OUTPUT);
    pinMode(YELLOW1, OUTPUT);
    digitalWrite(YELLOW1, HIGH);//S-V
    digitalWrite(YELLOW2, LOW);//S-V
    break;
    
    case 1:
    pinMode(YELLOW2, OUTPUT);
    pinMode(YELLOW1, OUTPUT);
    digitalWrite(YELLOW1, HIGH);// E(2)-V
    digitalWrite(YELLOW2, LOW);// E(2)-V
    break;
    
    case 2:
    pinMode(YELLOW2, OUTPUT);
    pinMode(YELLOW3, OUTPUT);
    digitalWrite(YELLOW3, HIGH);//N
    digitalWrite(YELLOW1, LOW);//N
    break;
  }
}


//NEED TO FLIP THE SIX
void Glow_Six(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(GREEN2, OUTPUT);
    pinMode(GREEN4, OUTPUT);
    digitalWrite(GREEN2, HIGH); //S
    digitalWrite(GREEN4, LOW); //S
    break;
    
    case 1:
    pinMode(GREEN2, OUTPUT);
    pinMode(GREEN4, OUTPUT);
    digitalWrite(GREEN4, HIGH); //I-X
    digitalWrite(GREEN2, LOW); //I-X
    break;
  }


}
void Glow_Five(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(PINK1, OUTPUT);
    pinMode(PINK2, OUTPUT);
    digitalWrite(PINK1, HIGH); //V-E
    digitalWrite(PINK2, LOW); //V-E
    break;
    
    case 1:
    pinMode(PINK1, OUTPUT);
    pinMode(PINK2, OUTPUT);
    digitalWrite(PINK2, HIGH); //F-I
    digitalWrite(PINK1, LOW); //F-I
    break;
  }
}

void Glow_Four(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(GREEN3, OUTPUT);
    pinMode(GREEN4, OUTPUT);
    digitalWrite(GREEN3, HIGH); //F-O
    digitalWrite(GREEN4, LOW); //F-O
    break;
    
    case 1:
    pinMode(GREEN3, OUTPUT);
    pinMode(GREEN1, OUTPUT);
    digitalWrite(GREEN3, HIGH); //U-R
    digitalWrite(GREEN1, LOW); //U-R
    break;
  }

}

//was spelled "tree" on board. needs to be fixed next time lol
void Glow_Three(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(GREEN4, OUTPUT);
    pinMode(GREEN1, OUTPUT);
    digitalWrite(GREEN4, HIGH); //T, "R" -> we will use this as H 
    digitalWrite(GREEN1, LOW); 
    break;
    
    case 1:
    pinMode(GREEN4, OUTPUT);
    pinMode(GREEN1, OUTPUT);
    digitalWrite(GREEN1, HIGH); //U-R
    digitalWrite(GREEN4, LOW); //U-R
    break;
  }

}


void Glow_Two(){
  pinMode(PINK1, OUTPUT);
  pinMode(PINK3, OUTPUT);
  
  digitalWrite(PINK3, HIGH); //T-W-O
  digitalWrite(PINK1, LOW); //T-W-O
  delay(DelayTime);
  resetPins();
  
}
void Glow_One(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(GREEN2, OUTPUT);
    pinMode(GREEN3, OUTPUT);
    digitalWrite(GREEN2, HIGH); //O-N
    digitalWrite(GREEN3, LOW); //O-N
    break;
    
    case 1:
    pinMode(GREEN3, OUTPUT);
    pinMode(GREEN1, OUTPUT);
    digitalWrite(GREEN1, HIGH); //E
    digitalWrite(GREEN3, LOW); //E
    break;
  }
  
}

void Glow_Past(int segment){
  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(RED4, OUTPUT);
    pinMode(RED1, OUTPUT);
    digitalWrite(RED4, HIGH); //p-a
    digitalWrite(RED1, LOW); //p-a
    break;
    
    case 1:
    pinMode(RED2, OUTPUT);
    pinMode(RED3, OUTPUT);
    digitalWrite(RED2, HIGH); //s-t
    digitalWrite(RED3, LOW); //s-t
    break;
  }
}

void Glow_OClock(int segment){

  segment = segment%2;
  switch(segment){
    case 0:
    pinMode(RED4, OUTPUT);
    pinMode(RED1, OUTPUT);
    digitalWrite(RED1, HIGH); //O,C
    digitalWrite(RED4, LOW); //O,C
    break;
    
    case 1:
    pinMode(RED4, OUTPUT);
    pinMode(RED3, OUTPUT);
    digitalWrite(RED3, HIGH); //C2,K
    digitalWrite(RED4, LOW); //C2,K
    break;
    
    case 2:
    pinMode(RED4, OUTPUT);
    pinMode(RED3, OUTPUT);
    digitalWrite(RED4, HIGH); //L,O
    digitalWrite(RED3, LOW); //L,O
  }
  
void resetPins(){
  //set all pins as input and as LOW 
  f||(i=0;i > NUM_OF_PINS; i++){
    pinMode(i, INPUT);
    digitalWrite(i, LOW)
  }
}
