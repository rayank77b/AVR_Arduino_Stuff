// Multi Function Shield fuer Andruino, Make Heft 2/2018


const uint8_t LED1 = 13;
const uint8_t LED2 = 12;
const uint8_t LED3 = 11;
const uint8_t LED4 = 10;
const uint16_t SPEED = 300;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
}

void loop()
{
  digitalWrite(LED1, LOW);
  delay(SPEED);
  digitalWrite(LED1, HIGH);
  
  digitalWrite(LED2, LOW);
  delay(SPEED);
  digitalWrite(LED2, HIGH);
  
  digitalWrite(LED3, LOW);
  delay(SPEED);
  digitalWrite(LED3, HIGH);
  
  digitalWrite(LED4, LOW);
  delay(SPEED);
  digitalWrite(LED4, HIGH);
}
