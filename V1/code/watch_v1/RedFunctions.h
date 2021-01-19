#define RED1 6
#define RED2 5
#define RED3 7
#define RED4 8


void resetRed();
void it_is(int i);
void to(int i);
void past(int i);
void Oclock(int i);
bool it_is_to_past_oclock(int i, bool enTo, bool enPast, bool enOclock);

/////////////*************************RED FUNCTIONS*******************************************///////


bool it_is_to_past_oclock(int i, bool enTo, bool enPast, bool enOclock){
  int y;
  resetRed();
  if(enTo == true){
    y= i%3;
    switch(y){
      case 0:
        it_is(0);
        break;
      case 1:
        it_is(1);
        break;
      case 2:
        to(0);
        break;
    }
    }
    

   if(enPast == true){
    y = y%4;
    switch(y){
      case 0:
        it_is(0);
        break;
      case 1:
        it_is(1);
        break;
      case 2:
        past(0);
        break;
      case 3:
        past(1);
        break;
    }
    }
  

    if(enOclock == true){
       y = y%5;
      switch(y){
      case 0:
        it_is(0);
        break;
      case 1:
        it_is(1);
        break;
      case 2:
        Oclock(0);
        break;
      case 3:
        Oclock(1);
        break;
      case 4:
        Oclock(2);
        break;
      }
    }
    


 if(enPast == true){
    y = i%4;
    switch(y){
      case 0:
        it_is(0);
        break;
      case 1:
        it_is(1);
        break;
      case 2:
        past(0);
        break;
      case 3:
        past(1);
        break;
    }
       
    }
    
}



void Oclock(int i){
  int x = i%3;
  
  switch(x){
    case 0:
    resetRed();
    pinMode(RED3, OUTPUT);
    pinMode(RED2, OUTPUT);
    digitalWrite(RED3, HIGH);
    digitalWrite(RED2, LOW);
    break;

    case 1:
    resetRed();
    pinMode(RED3, OUTPUT);
    pinMode(RED2, OUTPUT);
    digitalWrite(RED2, HIGH);
    digitalWrite(RED3, LOW);
    break;

    case 2:
    resetRed();
    pinMode(RED1, OUTPUT);
    pinMode(RED2, OUTPUT);
    digitalWrite(RED2, HIGH);
    digitalWrite(RED1, LOW);
    break;
    
  }
  
}



void to(int i){
  resetRed();
  pinMode(RED1, OUTPUT);
  pinMode(RED4, OUTPUT);
  digitalWrite(RED4, HIGH);
  digitalWrite(RED1, LOW);
}

void past(int i){
  
  switch(i){
    case 0: 
      resetRed();
      pinMode(RED1, OUTPUT);
      pinMode(RED2, OUTPUT);
      digitalWrite(RED1, HIGH);
      digitalWrite(RED2, LOW);
      break;
      //PA
    
    case 1:
      resetRed();
      pinMode(RED3, OUTPUT);
      pinMode(RED4, OUTPUT);
      digitalWrite(RED3, HIGH);
      digitalWrite(RED4, LOW);
      break;
      //ST

  }
}


void it_is(int i){
  
  resetRed();
  switch(i){
    case 0:
    resetRed();
    pinMode(RED1, OUTPUT);
    pinMode(RED4, OUTPUT);
    digitalWrite(RED1, HIGH);
    digitalWrite(RED4, LOW);
    //it
    break;

    case 1:
    resetRed();
    pinMode(RED3, OUTPUT);
    pinMode(RED4, OUTPUT);
    digitalWrite(RED4, HIGH);
    digitalWrite(RED3, LOW);
    //is
    break;  
  }
  
}

void resetRed(){
  pinMode(RED1, INPUT);
  pinMode(RED2, INPUT);
  pinMode(RED3, INPUT);
  pinMode(RED4, INPUT);

  
}
