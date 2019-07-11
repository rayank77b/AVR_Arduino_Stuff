int LATCH = 4;
int CLK = 7;
int DATA = 8;

int LCDPOS[4]={0xF8, 0xF4, 0xF2, 0xF1};
int LCDZAHL[10]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 };

void setup() {
  Serial.begin(9600);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  
  digitalWrite(LATCH, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(DATA,LOW);
}

void write(int wert, int pos) {
  int p = LCDPOS[pos-1];
  int w = LCDZAHL[wert];
  int i;
  
  digitalWrite(LATCH, LOW);
  for(i=7; i>=0; i--) {
      digitalWrite(DATA,!!(w&(1<<i)));
      digitalWrite(CLK, LOW);
      digitalWrite(CLK, HIGH);
  }
  
  for(i=7; i>=0; i--) {
      digitalWrite(DATA,!!(p&(1<<i)));
      digitalWrite(CLK, LOW);
      digitalWrite(CLK, HIGH);
  }
  
  digitalWrite(LATCH, HIGH);
}

void loop() {
  
    int sensorValue = analogRead(A0);
    int w=0;
    
    Serial.println(sensorValue);
    delay(1);
    w=sensorValue%10;
    write(w,1);
    delay(1);
    sensorValue=sensorValue/10;
    w=sensorValue%10;
    write(w,2);  
    delay(1);
    sensorValue=sensorValue/10;
    w=sensorValue%10;
    write(w,3);
    delay(1);
    sensorValue=sensorValue/10;
    w=sensorValue%10;
    write(w,4);
  
}delay(1);delay(1);delay(1);delay(1);
