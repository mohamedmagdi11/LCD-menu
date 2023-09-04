#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,20,4);

byte button1 = 4;
byte button2 = 3;
byte state1 = 0;
byte state2 = 0;
byte count = 0;

byte laststate1  ; 
byte laststate2  ;


byte choise[8] = {
  0b00000,
  0b10000,
  0b11000,
  0b11100,
  0b11110,
  0b11100,
  0b11000,
  0b10000
};

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  
  lcd.createChar(7, choise);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.home();
  lcd.write(7);
  lcd.print(" Select Program");
  lcd.setCursor(0,1);
  lcd.print(" Settings ");
}

void loop(){
  
  laststate1 = state1;
laststate2 = state2;

state1 =digitalRead(button1);
state2 =digitalRead(button2);
  state1 = 1-state1;
  state2 = 1-state2;
  

  
  if(state1 && laststate1==0 && count==0)
  {
  op2();
    count=1;
  }
  
  else if(state1 && laststate1==0 && count==1)
  {
  op3();
    count=2;
  }
  
 else if(state1 && laststate1==0 && count==2)
  {
  op4();
    count=3;
  }
  
 else if(state2 && laststate2==0 && count==1)
  {
  op1();
    count=0;
  }
  
 else if(state2 && laststate2==0 && count==2)
  {
  op2();
    count=1;
  }
  
else  if(state2 && laststate2==0 && count==3)
  {
  op3();
    count=2;
  }
}
      




void op1()
{
  lcd.clear();
  lcd.home();
  lcd.write(7);
  lcd.print(" Select Program");
  lcd.setCursor(0,1);
  lcd.print(" Settings ");
  
}

void op2()
{
  lcd.clear();
  lcd.home();  
  lcd.print(" Select Program");
  lcd.setCursor(0,1);
  lcd.write(7);
  lcd.print(" Settings ");
  
}

void op3()
{
  lcd.clear();
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print(" Settings ");
  lcd.setCursor(0,1);
  lcd.write(7);
  lcd.print(" Power Saving ");
  
}

void op4()
{
  lcd.clear();
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print(" Power Saving ");
  lcd.setCursor(0,1);
  lcd.write(7);
  lcd.print(" Shut down ");
  
}










