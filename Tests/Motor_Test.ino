#define PIN_MOT_IN1 5
#define PIN_MOT_IN2 6
#define PIN_MOT_IN3 10
#define PIN_MOT_IN4 11

void setup() 
{
  // Initialize motor pins as outputs
  pinMode(PIN_MOT_IN1, OUTPUT);
  pinMode(PIN_MOT_IN2, OUTPUT);
  pinMode(PIN_MOT_IN3, OUTPUT);
  pinMode(PIN_MOT_IN4, OUTPUT);
}

void loop() 
{
  // Test Motor Left Forward
  analogWrite(PIN_MOT_IN1, 150);
  analogWrite(PIN_MOT_IN2, 0);
  delay(2000); // Run for 2 seconds

  // Stop Motor Left
  analogWrite(PIN_MOT_IN1, 0);
  analogWrite(PIN_MOT_IN2, 0);
  delay(1000); // Pause for 1 second

  // Test Motor Left Backward
  analogWrite(PIN_MOT_IN1, 0);
  analogWrite(PIN_MOT_IN2, 150);
  delay(2000); // Run for 2 seconds

  // Stop Motor Left
  analogWrite(PIN_MOT_IN1, 0);
  analogWrite(PIN_MOT_IN2, 0);
  delay(1000); // Pause for 1 second

  // Test Motor Right Forward
  analogWrite(PIN_MOT_IN3, 150);
  analogWrite(PIN_MOT_IN4, 0);
  delay(2000); // Run for 2 seconds

  // Stop Motor Right
  analogWrite(PIN_MOT_IN3, 0);
  analogWrite(PIN_MOT_IN4, 0);
  delay(1000); // Pause for 1 second

  // Test Motor Right Backward
  analogWrite(PIN_MOT_IN3, 0);
  analogWrite(PIN_MOT_IN4, 150);
  delay(2000); // Run for 2 seconds

  // Stop Motor Right
  analogWrite(PIN_MOT_IN3, 0);
  analogWrite(PIN_MOT_IN4, 0);
  delay(1000); // Pause for 1 second
}