
#define PINK1 4 //PD4
#define PINK2 0 //PD0
#define PINK3 2 //PD2
#define PINK4 1 //PD1

/////////////*************************PINK FUNCTIONS*******************************************/////


void three(int i){
  i = i%3;
  switch(i){
    case 0:
      resetGreen();
      pinMode(GREEN1, OUTPUT);
      pinMode(GREEN3, OUTPUT);
      digitalWrite(GREEN1, HIGH);
      digitalWrite(GREEN3, LOW);
      break;
    case 1:
      resetGreen();
      pinMode(GREEN1, OUTPUT);
      pinMode(GREEN3, OUTPUT);
      digitalWrite(GREEN3, HIGH);
      digitalWrite(GREEN1, LOW);
      
      break;
    case 2:
      resetGreen();
      resetPink();
      pinMode(PINK1, OUTPUT);
      pinMode(PINK4, OUTPUT);
      digitalWrite(PINK1, HIGH);
      digitalWrite(PINK4, LOW);
      break;
  }
}

void eleven(int i){
  i = i%3;
  switch(i){
    case 0:
      resetPink();
      pinMode(PINK2, OUTPUT);
      pinMode(PINK4, OUTPUT);
      digitalWrite(PINK2, HIGH);
      digitalWrite(PINK4, LOW);
      break;
    case 1:
      resetPink();
      pinMode(PINK3, OUTPUT);
      pinMode(PINK4, OUTPUT);
      digitalWrite(PINK3, HIGH);
      digitalWrite(PINK4, LOW);
      break;
    case 2:
      pinMode(PINK3, OUTPUT);
      pinMode(PINK1, OUTPUT);
      digitalWrite(PINK3, HIGH);
      digitalWrite(PINK1, LOW);
      
  }
}



void fiveMinutes(int i){
 
  i = i%2;
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
  }
 
}


void eight(int i){
  
  i = i%3;
  switch(i){
    case 0:
      pinMode(PINK2, OUTPUT);
      pinMode(PINK4, OUTPUT);
      digitalWrite(PINK4, HIGH);
      digitalWrite(PINK2, LOW);
      break;
   case 1:
      resetPink();
      pinMode(PINK1, OUTPUT);
      pinMode(PINK2, OUTPUT);
      digitalWrite(PINK2, HIGH);
      digitalWrite(PINK1, LOW);
      break;
   case 2:
      resetPink();
      pinMode(PINK3, OUTPUT);
      pinMode(PINK4, OUTPUT);
      digitalWrite(PINK4, HIGH);
      digitalWrite(PINK3, LOW);
      break;
   
  }
}


void two(int i){
  
  i = i%2;
  switch(i){
    case 0:
      resetPink();
      pinMode(PINK1, OUTPUT);
      pinMode(PINK2, OUTPUT);
      digitalWrite(PINK1, HIGH);
      digitalWrite(PINK2, LOW);
      break;
    case 1:
      resetPink();
      pinMode(PINK1, OUTPUT);
      pinMode(PINK3, OUTPUT);
      digitalWrite(PINK1, HIGH);
      digitalWrite(PINK3, LOW);
      break;
  }
}
