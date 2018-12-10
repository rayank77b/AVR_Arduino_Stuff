// Multi Function Shield fuer Andruino, Make Heft 2/2018


const uint8_t LED1 = 13;
const uint8_t LED2 = 12;
const uint8_t LED3 = 11;
//const uint8_t BUZZER = 3;
const uint8_t BUTTON1 = A1;
const uint8_t BUTTON2 = A2;
const uint8_t BUTTON3 = A3;
const uint16_t SPEED = 300;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  //pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  //digitalWrite(BUZZER, HIGH);
}

void loop()
{
  if(!digitalRead(BUTTON1))
    digitalWrite(LED1, LOW);
  else
    digitalWrite(LED1, HIGH);
  
  if(!digitalRead(BUTTON2))
    digitalWrite(LED2, LOW);
  else
    digitalWrite(LED2, HIGH);
    
  if(!digitalRead(BUTTON3)) {
    //digitalWrite(BUZZER, LOW);
    digitalWrite(LED3, LOW);
  } else {
    //digitalWrite(BUZZER, HIGH);
    digitalWrite(LED3, HIGH);
  }
}
