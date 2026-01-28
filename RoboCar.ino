#include <HCSR04.h>
#include <SharpIR.h>

//Inputs
#define PIN_SENS_FLEFT A0
#define PIN_SENS_FRIGHT A1
#define PIN_BAT_LVL A2
#define PIN_SWITCH_VBRD A3
#define PIN_SENS_BACK_TRIG A4
#define PIN_SENS_BACK A5
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

// other definitions
#define SENSOR_NUMBER_SHARPIR 1080

HCSR04 hc(PIN_SENS_BACK_TRIG, PIN_SENS_BACK); //initialisation class HCSR04 (trig pin , echo pin)
SharpIRL SharpIR(PIN_SENS_FLEFT, SENSOR_NUMBER_SHARPIR);
ShrapIRR SharpIR(PIN_SENS_FRIGHT, SENSOR_NUMBER_SHARPIR);

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
  float distFrontLeft = SharpIRL.distance();
  float distFrontRight = SharpIRR.distance();
  float distBack = hc.dist();
  // Battery Level
  static unsigned short BatLvl= 0;
  BatLvl = analogRead(PIN_BAT_LVL);
  // Read switch state
  bool switch = analogRead(PIN_SWITCH_VBRD);

  // Always State transition conditions
  if ((distFrontLeft < 20) && (distFrontRight < 20) && (distBack < 10))
  {
    State = Caught;
  }

  if (BatLvl <= 725)
  {
    State = EmergencyStop;
  }

  switch (State)
  {
    case Idle:
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
      // Motors
      analogWrite(PIN_MOT_IN1, HIGH);
      analogWrite(PIN_MOT_IN2, LOW);
      analogWrite(PIN_MOT_IN3, HIGH);
      analogWrite(PIN_MOT_IN4, LOW);
      //Leds
      digitalWrite(PIN_LED_FRIGHT, LOW);
      digitalWrite(PIN_LED_FLEFT, LOW);
      digitalWrite(PIN_LED_BRight, LOW);
      digitalWrite(PIN_LED_BLeft, LOW);
      // Summer
      digitalWrite(PIN_SUMMER, LOW);

      // change state conditions
      if (switch == HIGH)
      {
        State = Idle;
      }
      
      if (distFrontLeft < 20)
      {
        State = TurnRight;
      }

      if (distFrontRight < 20)
      {
        State = TurnLeft;
      }

      if ((distFrontLeft < 20) && (distFrontRight < 20))
      {
        State = Backward;
      }
    break;
    case TurnLeft:
      // Motors
      analogWrite(PIN_MOT_IN1, LOW);
      analogWrite(PIN_MOT_IN2, LOW);
      analogWrite(PIN_MOT_IN3, HIGH);
      analogWrite(PIN_MOT_IN4, LOW);
      //Leds
      digitalWrite(PIN_LED_FRIGHT, LOW);
      digitalWrite(PIN_LED_FLEFT, HIGH);
      digitalWrite(PIN_LED_BRight, LOW);
      digitalWrite(PIN_LED_BLeft, HIGH);
      // Summer
      digitalWrite(PIN_SUMMER, LOW);

      // change state conditions
      if (switch == HIGH)
      {
        State = Idle;
      }
      // !add condition to go back to Forward when 90° is reached!
    break;
    case TurnRight:
      // Motors
      analogWrite(PIN_MOT_IN1, HIGH);
      analogWrite(PIN_MOT_IN2, LOW);
      analogWrite(PIN_MOT_IN3, LOW);
      analogWrite(PIN_MOT_IN4, LOW);
      //Leds
      digitalWrite(PIN_LED_FRIGHT, HIGH);
      digitalWrite(PIN_LED_FLEFT, LOW);
      digitalWrite(PIN_LED_BRight, HIGH);
      digitalWrite(PIN_LED_BLeft, LOW);
      // Summer
      digitalWrite(PIN_SUMMER, LOW);

      // change state conditions
      if (switch == HIGH)
      {
        State = Idle;
      }
      // !add condition to go back to Forward when 90° is reached!
    break;
    case Backward:
      // Motors
      analogWrite(PIN_MOT_IN1, LOW);
      analogWrite(PIN_MOT_IN2, HIGH);
      analogWrite(PIN_MOT_IN3, LOW);
      analogWrite(PIN_MOT_IN4, HIGH);
      //Leds
      digitalWrite(PIN_LED_FRIGHT, LOW);
      digitalWrite(PIN_LED_FLEFT, LOW);
      digitalWrite(PIN_LED_BRight, HIGH);
      digitalWrite(PIN_LED_BLeft, HIGH);
      // Summer
      digitalWrite(PIN_SUMMER, HIGH);

      // change state conditions
      if (switch == HIGH)
      {
        State = Idle;
      }

      if (distBack < 10)
      {
        State = Forward;
      }
      // !add condition to leave state after certain time!
    break;
    case EmergencyStop:
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
      digitalWrite(PIN_SUMMER, HIGH);

      // change state conditions
      if (switch == HIGH)
      {
        State = Idle;
      }
    break;
    case Caught:
      // change state conditions
      if (switch == HIGH)
      {
        State = Idle;
      }
    break;
  }
}