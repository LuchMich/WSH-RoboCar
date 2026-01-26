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
#define PIN_LED_BACK 9
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

}

void loop() 
{

}
