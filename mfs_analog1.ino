// Multi Function Shield fuer Andruino, Make Heft 2/2018


const uint8_t POTI = A0;
uint16_t ADwert;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ADwert = analogRead(POTI);
  Serial.print("Poti AD: ");
  Serial.print(ADwert);
  Serial.print(" = ");
  Serial.print(double(ADwert*0.0048828),2);
  Serial.print(" V\n");
  delay(500);
}
