int led = 13;

//setup
pinMode(led, OUTPUT);  
pinMode(pushButton, INPUT);
Serial.begin(9600);

//loop
digitalWrite(led, HIGH);
delay(3000);           
digitalWrite(led, LOW);  

int sensorValue = analogRead(A0);
Serial.println(sensorValue);

int buttonState = digitalRead(pushButton);
Serial.println(buttonState);
digitalWrite(13, buttonState);

// je nach INPUT oder OUTPUt wird unterschiedliche .. genutzt
// bei PWM Pins wird bei OUTPUT, die PWM produziert
analogWrite(led, brightness);
