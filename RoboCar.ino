#include <HCSR04.h>
#include <SharpIR.h>

//Inputs
#define PIN_SENS_BACK A5
#define PIN_SENS_FLEFT A0
#define PIN_SENS_FRIGHT A1
#define PIN_BAT_LVL A2
#define PIN_SWITCH_VBRD A3
#define PIN_TG_L 2
#define PIN_TG_R 3

//Outputs
#define PIN_MOT_IN1 5
#define PIN_MOT_IN2 6
#define PIN_MOT_IN3 10
#define PIN_MOT_IN4 11
#define PIN_LED_FRIGHT 7
#define PIN_LED_FLEFT 8
#define PIN_LED_BRight 9
#define PIN_LED_BLeft 12
#define PIN_SUMMER 4

typedef enum {
    Idle = 0,
    Forward,
    TurnLeft,
    TurnRight,
    Backward,
    EmergencyStop,
    Caught
} RoboState;

RoboState State;

void setup() 
{
  // Pins Output
  pinMode(PIN_MOT_IN1, OUTPUT);
  pinMode(PIN_MOT_IN2, OUTPUT);
  pinMode(PIN_MOT_IN3, OUTPUT);
  pinMode(PIN_MOT_IN4, OUTPUT);
  pinMode(PIN_LED_FRIGHT, OUTPUT);
  pinMode(PIN_LED_FLEFT, OUTPUT);
  pinMode(PIN_LED_BRight, OUTPUT);
  pinMode(PIN_LED_BLeft, OUTPUT);
  pinMode(PIN_SUMMER, OUTPUT);

  // Pins Input
  pinMode(PIN_TG_L, INPUT);
  pinMode(PIN_TG_R, INPUT);

  State = Idle;
}

void loop() 
{
  // Read sensor values
  // Read switch state
  bool switch = analogRead(PIN_SWITCH_VBRD);

  switch (State)
  {
    case Idle:
      // Code for Idle state

      // Motors
      analogWrite(PIN_MOT_IN1, LOW);
      analogWrite(PIN_MOT_IN2, LOW);
      analogWrite(PIN_MOT_IN3, LOW);
      analogWrite(PIN_MOT_IN4, LOW);
      //Leds
      digitalWrite(PIN_LED_FRIGHT, HIGH);
      digitalWrite(PIN_LED_FLEFT, HIGH);
      digitalWrite(PIN_LED_BRight, HIGH);
      digitalWrite(PIN_LED_BLeft, HIGH);
      // Summer
      digitalWrite(PIN_SUMMER, LOW);
      // change state conditions
      if (switch == HIGH)
      {
        State = Forward;
      }
    break;
    case Forward:
      // Code for Forward state
      if (switch == High)
      {
        State = Idle;
      }
    break;
    case TurnLeft:
      // Code for TurnLeft state
      if (switch == High)
      {
        State = Idle;
      }      
    break;
    case TurnRight:
      // Code for TurnRight state
      if (switch == High)
      {
        State = Idle;
      }
    break;
    case Backward:
      // Code for Backward state
      if (switch == High)
      {
        State = Idle;
      }
    break;
    case EmergencyStop:
      // Code for EmergencyStop state
      if (switch == High)
      {
        State = Idle;
      }
    break;
    case Caught:
      // Code for Caught state
      if (switch == High)
      {
        State = Idle;
      }
    break;
  }
}
