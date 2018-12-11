// Multi Function Shield fuer Andruino, Make Heft 2/2018
const uint8_t LATCH = 4;
const uint8_t CLK = 7;
const uint8_t DATA = 8;

const uint8_t SEGMENT_MAP[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
const uint8_t SEGMENT_SELECT[] = {0xf1,0xf2,0xf4,0xf8};

void ShiftOutData(uint8_t v)
{
  uint8_t i;
  for(i=0; i<8; i++)
  {
    digitalWrite(DATA, !!(v&(1<<(7-i))));
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }
}

void WriteNumberToSegment(uint8_t digit, uint8_t v)
{
  digitalWrite(LATCH, LOW);
  ShiftOutData(SEGMENT_MAP[v]);
  ShiftOutData(SEGMENT_SELECT[digit]);
  digitalWrite(LATCH, HIGH);
}

void DisplayNumber(uint16_t v)
{
  WriteNumberToSegment(0,v/1000);
  WriteNumberToSegment(1,(v/100)%10);
  WriteNumberToSegment(2,(v/10)%10);
  WriteNumberToSegment(3,v%10);
}

void setup() 
{
  pinMode(LATCH,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(DATA,OUTPUT);
}

void loop()
{
  //DisplayNumber(3210);
  //delay(2000);
  DisplayNumber(789);
  //delay(2000);
}
