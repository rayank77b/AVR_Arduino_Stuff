// einfach Schrittmotor steuerung
// step motor 28BYJ-48
// Treiber ULN2003APC

const uint8_t N1 = A0;
const uint8_t N2 = A1;
const uint8_t N3 = A2;
const uint8_t N4 = A3;
const uint8_t WAIT = 1;

const uint8_t LED1 = 13;
const uint8_t BUTTON1 = 7;
const uint8_t BUTTON2 = 8;

uint8_t dir = 0;

void direction1()
{
  delay(WAIT);            //1
  digitalWrite(N1, HIGH);
  digitalWrite(N2, LOW);
  digitalWrite(N4, LOW);
  digitalWrite(N4, LOW);
  delay(WAIT);            //2
  digitalWrite(N1, HIGH);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  delay(WAIT);            //3
  digitalWrite(N1, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  delay(WAIT);            //4
  digitalWrite(N1, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  delay(WAIT);            //5
  digitalWrite(N1, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  delay(WAIT);            //6
  digitalWrite(N1, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, HIGH);
  delay(WAIT);            //7
  digitalWrite(N1, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
  delay(WAIT);            //8
  digitalWrite(N1, HIGH);
  digitalWrite(N2, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
}

void direction2()
{
  delay(WAIT);            //1
  digitalWrite(N4, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
  delay(WAIT);            //2
  digitalWrite(N4, HIGH);
  digitalWrite(N3, HIGH);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
  delay(WAIT);            //3
  digitalWrite(N4, LOW);
  digitalWrite(N3, HIGH);
  digitalWrite(N2, LOW);
  digitalWrite(N1, LOW);
  delay(WAIT);            //4
  digitalWrite(N4, LOW);
  digitalWrite(N3, HIGH);
  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  delay(WAIT);            //5
  digitalWrite(N4, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N1, LOW);
  delay(WAIT);            //6
  digitalWrite(N4, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N1, HIGH);
  delay(WAIT);            //7
  digitalWrite(N4, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, HIGH);
  delay(WAIT);            //8
  digitalWrite(N4, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N1, HIGH);
}

void setup()
{
  pinMode(N1,OUTPUT);
  pinMode(N2,OUTPUT);
  pinMode(N3,OUTPUT);
  pinMode(N4,OUTPUT);
  digitalWrite(N1, LOW);
  digitalWrite(N2, LOW);
  digitalWrite(N3, LOW);
  digitalWrite(N4, LOW);
  
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
   digitalWrite(LED1, HIGH);
}

void loop()
{
  if(!digitalRead(BUTTON1))
    dir = 1;
  if(!digitalRead(BUTTON2))
    dir = 0;
  
  if(dir==1) {
    direction1();
  } else {
    direction2();
  }
}
