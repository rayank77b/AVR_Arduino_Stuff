#include <LiquidCrystal.h>
// bei 1601 wird nur die erste haelfte angezeigt
// dei 2te nicht.
// ist nicht defekt, sondern falscher "addressraum"
// richtig ist 8x2 und nicht 16x1, oder man muss ein paar stellen weiter schreiben
// siehe beispiel aus internent.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
    lcd.begin(16,2);     // or lcd.begin(8,2);
    lcd.print("First8ch");
    lcd.setCursor(40,0); // Works for showing characters on the right half of GDM1601A controlled 16x1 LCD displays.
    lcd.print("Last8ch.");
  }
void loop()
  {
  }
