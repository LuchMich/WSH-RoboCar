#define PIN_BAT_LVL A2
#define PIN_SUMMER 4

void setup() 
{
  Serial.begin(300);
  pinMode(PIN_SUMMER, OUTPUT);
}

void loop() 
{
  static unsigned short BatLvl= 0;
  BatLvl = analogRead(PIN_BAT_LVL);
  Serial.println(BatLvl);
  if (BatLvl <= 725)
    digitalWrite(PIN_SUMMER, 1);
  else
    digitalWrite(PIN_SUMMER, 0);
}