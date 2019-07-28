const int STEP = 7;
const int DIR = 8;
const int LED =13;
int incomingByte = 0;
int mydelay=50;
int cnt=0;

void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW); 
  digitalWrite(STEP, LOW); 
  digitalWrite(DIR, LOW); 
}

void loop() {
  incomingByte = Serial.read();
  
  int i;
  if(incomingByte==43) {
    mydelay++;
    if(mydelay>254) {
      mydelay=254;
    }
  }
  if(incomingByte==45) {
    mydelay--;
    if(mydelay<1) {
      mydelay=1;
    }
  }
  cnt++;
  if(cnt==254) {
    Serial.println(mydelay);
    cnt=0;
  }
  digitalWrite(STEP, HIGH);
  delay(mydelay);
  digitalWrite(STEP, LOW);
  
}
