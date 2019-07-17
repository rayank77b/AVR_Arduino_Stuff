const int STEP = 7;
const int DIR = 8;
const int LED =13;
int incomingByte = 0;


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
  delay(20);
  incomingByte = Serial.read();
  digitalWrite(LED, HIGH);
  //Serial.println(incomingByte, DEC);
  int i;
  if(incomingByte==76) {
    digitalWrite(DIR, HIGH);
    Serial.println("direction HIGH");
  }
  if(incomingByte==82) {
    digitalWrite(DIR, LOW);
    Serial.println("direction LOW");
  }
  if(incomingByte>48 && incomingByte<58) {
    int cnt=(incomingByte-48)*28;
    Serial.println(cnt);
    for(i=0;i<cnt;i++) {
      digitalWrite(STEP, HIGH);
      delay(10);
      digitalWrite(STEP, LOW);
    }
  }
  delay(20);
  digitalWrite(LED, LOW);
}
