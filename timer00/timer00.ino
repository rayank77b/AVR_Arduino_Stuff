int CLK = 13;
int v=HIGH;

void setup() {
  
  pinMode(CLK, OUTPUT);
  
}


void loop() {
   delay(1000);
   digitalWrite(CLK, LOW);
   
    delay(1000);
    digitalWrite(CLK, HIGH);
}

