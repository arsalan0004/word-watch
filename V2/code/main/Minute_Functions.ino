#define MIN1 17//PC3
#define MIN2 0//PD0
#define MIN3 1//PD1
#define MIN4 2//PD2
#define MIN5 8//PB0
#define MIN6 5//PD5


void set_MinPins_INPUT(){
  pinMode(MIN1, INPUT);
  pinMode(MIN2, INPUT);
  pinMode(MIN3, INPUT);
  
  pinMode(MIN4, INPUT);
  pinMode(MIN5, INPUT);
  pinMode(MIN6, INPUT);
}

void five_Minutes(int i){
  //involves pins 'min3' and 'min5'
  pinMode(MIN3, OUTPUT); pinMode(MIN5, OUTPUT);
  
   i = i%2;
  switch(i){
    case 0:
      digitalWrite(MIN3, HIGH); digitalWrite(MIN5, LOW); //glows 'F' and 'I'
      break;
      
    case 1:
      digitalWrite(MIN5, HIGH); digitalWrite(MIN3, LOW); //glows 'E' and 'V'
      break;
  }
}

void ten_Minutes(int i){
  //involves pins 'min2' and 'min3' and 'min6'

  pinMode(MIN6, OUTPUT);
  
  i = i%2;
  switch(i){
    case 0:
      pinMode(MIN2, OUTPUT);
      digitalWrite(MIN6, HIGH); digitalWrite(MIN2, LOW); //glows 'T' and 'W'
      break;
      
    case 1:
      pinMode(MIN2, INPUT); pinMode(MIN3, OUTPUT);
      digitalWrite(MIN3, HIGH); digitalWrite(MIN6, LOW); //glows 'E' and 'N'
      pinMode(MIN3, INPUT);
      break;
  }
  
}

void fifteen_Minutes(int i){
  //lights up 'quarter' as in 'quarter past five'
  //involves pins 'min1', 'min2', and 'min6'

  pinMode(MIN6, OUTPUT);
  
  switch(i){
    case 0:
      pinMode(MIN1, OUTPUT);
      digitalWrite(MIN1, HIGH); digitalWrite(MIN6, LOW); //glows 'U' and first 'R'
      break;
      
    case 1:
      digitalWrite(MIN6, HIGH); digitalWrite(MIN1, LOW); // glows 'Q' and 'A'
      break;

    case 2:
      pinMode(MIN1, INPUT); pinMode(MIN2, OUTPUT);
      digitalWrite(MIN2, HIGH); // glows 'T' and 'E'
      break;
  }
  
}

void twenty_Minutes(int i){
  //involves pins 'min1' and 'min2' and 'min5'
  
  pinMode(MIN5, OUTPUT);
  
  i = i%3;
  switch(i){
    case 0:
      pinMode(MIN2,INPUT); pinMode(MIN1, OUTPUT);
      digitalWrite(MIN5, HIGH); digitalWrite(MIN1, LOW); //glows 'T' and 'W'
      break;
      
    case 1:
      pinMode(MIN2, OUTPUT); pinMode(MIN1, INPUT);
      digitalWrite(MIN2, HIGH); digitalWrite(MIN5, LOW); //glows 'E' and 'N'
      break;
      
   case 2:
      digitalWrite(MIN5, HIGH); digitalWrite(MIN2, LOW); //glows '2nd T' and 'Y'
      break;
  }
  
}

void twentyFive_Minutes(int i){
  //involves pins 'Min1', 'Min2','Min3' and 'Min5'
  pinMode(MIN5, OUTPUT);

  i = i%5;
  switch(i){
    case 0:
      pinMode(MIN3, INPUT); pinMode(MIN1, OUTPUT);
      digitalWrite(MIN5, HIGH); digitalWrite(MIN1, LOW); //glows 'T' and 'W' (of Twenty)
      break;
      
    case 1:
      pinMode(MIN1, INPUT); pinMode(MIN2, OUTPUT); 
      digitalWrite(MIN2, HIGH); digitalWrite(MIN5, LOW); //glows 'E' and 'N' (of Twenty)
      break;
      
   case 2:
      digitalWrite(MIN5, HIGH); digitalWrite(MIN2, LOW); //glows '2nd T' and 'Y' (of Twenty)
      break;
   
   case 3:
      pinMode(MIN2,INPUT); pinMode(MIN3, OUTPUT);
      digitalWrite(MIN3, HIGH); digitalWrite(MIN5, LOW); //glows 'F' and 'I'
      break;
      
   case 4:
      digitalWrite(MIN5, HIGH); digitalWrite(MIN3, LOW); //glows 'E' and 'V'
      break;
      
  }
}

void thirty_Minutes(int i){
  //lights up 'half', as in, 'half past three'
  //involves pins 'Min3' and 'Min4'
  pinMode(MIN3, OUTPUT); pinMode(MIN4, OUTPUT);

  i = i%2;
  switch(i){
    case 0:
      digitalWrite(MIN3, HIGH); digitalWrite(MIN4, LOW); //glows 'H' and 'A'
      break;
      
    case 1:
      digitalWrite(MIN4, HIGH); digitalWrite(MIN3, LOW); //glows 'F' and 'L'
      break;
  }
}
