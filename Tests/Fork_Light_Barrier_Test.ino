//define constants for pin assignments
#define PIN_MOT_IN1 5
#define PIN_MOT_IN3 10
#define PIN_TG_L 2
#define PIN_TG_R 3

void setup() 
{
  Serial.begin(9600);
  // Initialize motor and trigger pins as outputs/inputs
  pinMode(PIN_TG_L, INPUT);
  pinMode(PIN_TG_R, INPUT);
  pinMode(PIN_MOT_IN1, OUTPUT);
  pinMode(PIN_MOT_IN3, OUTPUT);
}

void loop() 
{
  // Static counters to keep track of trigger activations
  static unsigned long CountLeft = 0;
  static unsigned long CountRight = 0;

  // Activate motors at a set PWM speed
  analogWrite(PIN_MOT_IN1, 100);
  analogWrite(PIN_MOT_IN3, 100);

  if (digitalRead(PIN_TG_L) == 1)
  {
    CountLeft++;
  }
  if (digitalRead(PIN_TG_R) == 1)
  {
    CountRight++;
  }

  Serial.println("Counter Left: CountLeft");
  Serial.println("Counter Right: CountRight");
}