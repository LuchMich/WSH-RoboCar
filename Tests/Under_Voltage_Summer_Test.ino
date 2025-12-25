//define constants for pin assignments
#define PIN_BAT_LVL A2
#define PIN_SUMMER 4

void setup() 
{
  Serial.begin(300);
  //initialize pin modes
  pinMode(PIN_SUMMER, OUTPUT);
}

void loop() 
{
  //variable to hold battery level reading
  static unsigned short BatLvl= 0;

  BatLvl = analogRead(PIN_BAT_LVL);
  Serial.println(BatLvl);

  if (BatLvl <= 725)
    digitalWrite(PIN_SUMMER, 1);
  else
    digitalWrite(PIN_SUMMER, 0);
}