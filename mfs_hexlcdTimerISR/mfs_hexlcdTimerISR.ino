int LATCH = 4;
int CLK = 7;
int DATA = 8;

int LCDPOS[4]={0xF8, 0xF4, 0xF2, 0xF1};
int LCDZAHL[10]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 };
int sensorValue=0;
int WERT[4];

void setup() {
  
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  
  digitalWrite(LATCH, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(DATA,LOW);
  
  TCCR0A=(1<<WGM01);    //Set the CTC mode   
  OCR0A=155;            //Value for ORC0A for 10ms
 
  TIMSK0|=(1<<OCIE0A);   //Set the interrupt request
  sei();                 //Enable interrupt
 
  TCCR0B|=(1<<CS02);    //Set the prescale 1/1024 clock
  TCCR0B|=(1<<CS00);
}

void write(int wert, int pos) {
  int p = LCDPOS[pos];
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
   
    int i;
    
    for(i=0;i<4;i++) {
      write(WERT[i], i);
    }
  
}

ISR(TIMER0_COMPA_vect){    //This is the interrupt request
  sensorValue = analogRead(A0);
  WERT[0]=sensorValue%10;
  sensorValue=sensorValue/10;
  WERT[1]=sensorValue%10;
  sensorValue=sensorValue/10;
  WERT[2]=sensorValue%10;
  sensorValue=sensorValue/10;
  WERT[3]=sensorValue%10;
}
