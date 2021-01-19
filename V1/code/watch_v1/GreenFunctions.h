#define GREEN1 9
#define GREEN2 14
#define GREEN3 15
#define GREEN4 10

void resetGreen(){
  pinMode(GREEN1, INPUT);
  pinMode(GREEN2, INPUT);
  pinMode(GREEN3, INPUT);
  pinMode(GREEN4, INPUT);
}



/////////////*************************GREEN FUNCTIONS*******************************************/////


void four(int i){
  
  i = i%2;
  switch(i){
    case 0:
      resetGreen();
      pinMode(GREEN3, OUTPUT);
      pinMode(GREEN2, OUTPUT);
      digitalWrite(GREEN2, HIGH);
      digitalWrite(GREEN3, LOW);
      break;
    case 1:
      resetGreen();
      pinMode(GREEN1, OUTPUT);
      pinMode(GREEN2, OUTPUT);
      digitalWrite(GREEN1, HIGH);
      digitalWrite(GREEN2, LOW);
      break;
  }
}


void six(int i){
  i = i%2;
  switch(i){
    case 0:
      resetGreen();
      pinMode(GREEN3, OUTPUT);
      pinMode(GREEN4, OUTPUT);
      digitalWrite(GREEN3, HIGH);
      digitalWrite(GREEN4, LOW);
      break;
      //ix
    case 1:
      resetGreen();
      pinMode(GREEN3, OUTPUT);
      pinMode(GREEN2, OUTPUT);
      digitalWrite(GREEN3, HIGH);
      digitalWrite(GREEN2, LOW);
      break;
      //s
  }
}

void one(int i){
  i = i%2;
  switch(i){
    case 0:
      resetGreen();
      pinMode(GREEN3, OUTPUT);
      pinMode(GREEN4, OUTPUT);
      digitalWrite(GREEN4, HIGH);
      digitalWrite(GREEN3, LOW);
      break;
      //E
    case 1:
      resetGreen();
      pinMode(GREEN2, OUTPUT);
      pinMode(GREEN4, OUTPUT);
      digitalWrite(GREEN2, HIGH);
      digitalWrite(GREEN4, LOW);
      break;
      //ON
}
}



void twelve(int i){
  
  i = i%2;
  switch(i){
    case 0:
      resetGreen();
      pinMode(GREEN1, OUTPUT);
      pinMode(GREEN4, OUTPUT);
      digitalWrite(GREEN1, HIGH);
      digitalWrite(GREEN4, LOW);
      break;
    case 1:
      resetGreen();
      pinMode(GREEN1, OUTPUT);
      pinMode(GREEN4, OUTPUT);
      digitalWrite(GREEN4, HIGH);
      digitalWrite(GREEN1, LOW);
      break;
   case 2:
      resetGreen();
      pinMode(GREEN2, OUTPUT);
      pinMode(GREEN4, OUTPUT);
      digitalWrite(GREEN4, HIGH);
      digitalWrite(GREEN2, LOW);
      break;
 
  }
}
