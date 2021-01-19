#define PCF8523_ADDR 0x68


volatile int currentMinutes =0;
volatile int currentHours = 0;

byte bcdToDec(byte value)
{
  return ((value / 16) * 10 + value % 16);
}

byte decToBcd(byte value){
  return (value / 10 * 16 + value % 10);
}

void readPCF8523(){
  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(0x04);
  Wire.endTransmission();
  
  Wire.requestFrom(PCF8523_ADDR, 2);
  currentMinutes = Wire.read();
  currentHours = Wire.read();

  currentMinutes = bcdToDec(currentMinutes);
  currentHours = bcdToDec(currentHours);
  
  

  
}

void setPCF8523(int hour, int minute)
// this sets the time and date to the PCF8563
{
  
  int second = 0;
  int dayOfWeek = 3;
  int dayOfMonth =3;
  int month = 3;
  int year = 2015; 
  int PCF8523_CONTROL_1_REG;

  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(0x00); //control 1 register
  Wire.endTransmission(); 

  Wire.requestFrom(PCF8523_ADDR, 1);
  PCF8523_CONTROL_1_REG = Wire.read();

  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(PCF8523_CONTROL_1_REG | (1<<3)); //set bit 3, enabling 12-hour mode
  Wire.endTransmission();
  
  Wire.beginTransmission(PCF8523_ADDR);
  Wire.write(0x03); //seconds register
  Wire.write(decToBcd(second));  
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));     
  Wire.write(decToBcd(dayOfMonth));
  Wire.write(decToBcd(dayOfWeek));  
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.endTransmission();

  

  
  
}
