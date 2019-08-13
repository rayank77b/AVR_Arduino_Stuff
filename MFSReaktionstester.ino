#include <TimerOne.h>
#include <MultiFuncShield.h>

unsigned long timeRandom;
unsigned long timeStart;
unsigned long timeEnd;
unsigned long myTimeStart;
unsigned long myTimeEnd;

byte game;
long randNumber;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
  game=0;
  timeRandom=millis();
  randomSeed(timeRandom);
  Serial.begin(9600);
  MFS.writeLeds(LED_1|LED_2|LED_3|LED_4, OFF); 
}

void loop() {
  byte btn = MFS.getButton();

  if(game==1) {
    timeEnd = millis();
    if((timeStart+randNumber)< timeEnd){
      MFS.writeLeds(LED_1|LED_2|LED_3|LED_4, ON); 
      game=2;
      myTimeStart = millis();
    }
  }
  
  if (btn == BUTTON_1_PRESSED){
    if(game==0) {
      game=1;
      timeStart = millis();
      randNumber = random(1000,3000);
      MFS.write ("Strt");
    }
    if(game==2) {
      MFS.writeLeds(LED_1|LED_2|LED_3|LED_4, OFF); 
      game=0;
      myTimeEnd = millis();
      Serial.print("Game time in ms: ");
      Serial.println(myTimeEnd-myTimeStart);
      MFS.write((int)(myTimeEnd-myTimeStart));
    }
    /*if(game==1) {
      timeEnd = millis();
      if((timeStart+randNumber)> timeEnd){
        MFS.write("Eror");
        game=0;
      }
    }*/
  }
}
