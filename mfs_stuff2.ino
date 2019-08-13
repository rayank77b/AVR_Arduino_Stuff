#include <TimerOne.h>
#include <MultiFuncShield.h>
  
byte leds;
void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
}

void loop() {
  byte btn = MFS.getButton();

  if (btn == BUTTON_1_PRESSED){
    MFS.write (leds);
    if((leds&1)==1) {
      MFS.writeLeds(LED_1, OFF);  
      leds=leds-1;
    } else {
      MFS.writeLeds(LED_1, ON);  
      leds=leds+1;
    }
  }
  if (btn == BUTTON_2_PRESSED){
    MFS.write (leds);
    if((leds&2)==2) {
      MFS.writeLeds(LED_2, OFF);  
      leds=leds-2;
    } else {
      MFS.writeLeds(LED_2, ON);  
      leds=leds+2;
    }
  }
  if (btn == BUTTON_3_PRESSED){
    MFS.write (leds);
    if((leds&4)==4) {
      MFS.writeLeds(LED_3, OFF);  
      leds=leds-4;
    } else {
      MFS.writeLeds(LED_3, ON);  
      leds=leds+4;
    }
  }
}
