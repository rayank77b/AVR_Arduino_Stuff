#include <TimerOne.h>
#include <MultiFuncShield.h>
  
int leds;
void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);
}

void loop() {
  MFS.write (-100);
  delay (1000);
  MFS.writeLeds(LED_1, ON);  
  MFS.writeLeds(LED_2, OFF);  
  for(i=-25;i++;i<1) {
    MFS.write(i);
    delay(150);
  }
  MFS.writeLeds(LED_2, ON);  
  MFS.writeLeds(LED_1, OFF);  
  for(i=-25;i++;i<1) {
    MFS.write(25+i);
    delay(150);
  }
  MFS.writeLeds(LED_2, OFF);  
  MFS.writeLeds(LED_1, OFF);  
  MFS.write ("aaaa");
  delay (1000);
}
