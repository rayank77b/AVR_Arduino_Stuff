// wie schnell kann man analog lesen.
// laut datenblat sind min 0.1ms nötig
// durch lesen in ram und dann durch auswertung
// sind 0.12ms mindestens gewesen.

int values[512];
//int values;
int i;
int cnt_low;
int cnt_high;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  //Serial.begin(230400);
  for(i=0;i<512;i++) {
    values[i]=0;
  }

}

// the loop routine runs over and over again forever:
void loop() {
  for(i=0;i<512;i++) {
    values[i] = analogRead(A0);
  }
  for(i=0;i<512;i++) {
    Serial.println(values[i]);
  }
    
  delay(5000);
}
