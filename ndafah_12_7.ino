#include <Event.h>
#include <Timer.h>

#include "TimerOne.h"
#include <PID_v1.h>
#include <Ultrasonic.h>

/******************************* pid setting ***********************/
// MOVING RIGHT PID by forward sensor cm[8](odam) & cm[1](warah)
double Setpoint = 0, Input_mr, Output_mr;   //Define Variables
double Kp_mr = 7, Ki_mr = 0, Kd_mr = 1.7;     //moving right pid parameters 4 0 1.1

//for 254 val 4 0 1.88
PID PID_MR(&Input_mr, &Output_mr, &Setpoint, Kp_mr, Ki_mr, Kd_mr, DIRECT); ///moving right pid
uint16_t LMS_MR;    //Lift Motor Speed
uint16_t RMS_MR;    //Right Motor Speed


// MOVING FORWARD PID by left sensor cm[2](odam) & cm[3](warah)
double  Input_f, Output_f;   //Define Variables
double Kp_f = 6 , Ki_f = 0, Kd_f = 1.88; //forward pid parameters 4 0 1.2
PID PID_F(&Input_f, &Output_f, &Setpoint, Kp_f, Ki_f, Kd_f, DIRECT); ///moving forward
uint16_t LMS_F;    //Lift Motor Speed
uint16_t RMS_F;    //Right Motor Speed


// MOVING FORWARD PID by right sensor cm[7](odam) &cm[6] (warah)
double  Input_fr, Output_fr;   //Define Variables
double Kp_fr = 4, Ki_fr = 0, Kd_fr = 1.88; //forward pid parameters 4 0 1.2
PID PID_Fr(&Input_fr, &Output_fr, &Setpoint, Kp_fr, Ki_fr, Kd_fr, DIRECT); ///moving forward
uint16_t LMS_Fr;    //Lift Motor Speed
uint16_t RMS_Fr;    //Right Motor Speed


// MOVING RIGHT PID by backward sensor cm[5](odam) & cm[4](warah)
double  Input_b, Output_b;   //Define Variables
double Kp_b = 7, Ki_b = 0, Kd_b = 1.7; //forward pid parameters 4 0 1.2
PID PID_B(&Input_b, &Output_b, &Setpoint, Kp_b, Ki_b, Kd_b, DIRECT); ///moving forward
uint16_t LMS_B;    //Lift Motor Speed
uint16_t RMS_B;    //Right Motor Speed

//// **start**MOVING RIGHT PID by backward sensor cm[5](odam) & cm[4](warah)
double  Input_start, Output_start;   //Define Variables
double Kp_start = 6, Ki_start = 0, Kd_start = 1.4; //forward pid parameters 4 0 1.2
PID PID_start(&Input_start, &Output_start, &Setpoint, Kp_start, Ki_start, Kd_start, DIRECT); ///moving forward
uint16_t LMS_start;    //Lift Motor Speed
uint16_t RMS_start;    //Right Motor Speed

/******************************************************************************/

/**uln***/
//ULNs Pins
#define sol 47
#define val3 49
#define val4 51
#define val5 45
#define vent 43

#define grip 53

/**************MOTORS PINS   ***/

//defining direction HIGH for go_forward
#define dir4 A4 //up LEFT
#define dir1 17 //down LEFT
#define dir2 A5 //up RIGHT
#define dir3 16 //down RIGHT
//definining switch
#define pwm4 8
#define pwm1 6
#define pwm2 7
#define pwm3 5

#define dproximityR 12 // select a digital pin to read the o/p of the proximity sensor which detects the junction
#define dproximityL 11 // select a digital pin to read the o/p of the proximity sensor which detects the junction
#define dproximitySh 13 // select a digital pin to read the o/p of the proximity sensor which detects the COLOR of the shuttle
int proximityR;
int proximityL; // the integer that saves the o/p of the sensor (0 NORMAl /1 Gold)
int proximitySh;  
//flash
#define flash_pin 14
volatile bool flash_state = 0;
//defining direction HIGH for go_forward
#define go_forward HIGH
#define go_backward LOW

#define max_speed 254
int val = 120;
/****************/

/*****ultrasonic*****/
#define UltraTrig1 A9
#define UltraTrig9 A11
#define UltraTrig2 32
#define UltraTrig3 50
#define UltraTrig4 48
#define UltraTrig5 38
#define UltraTrig6 20
#define UltraTrig7 19
#define UltraTrig8 A1
#define UltraTrig0 000

#define UltraEco1 A8
#define UltraEco9 A10
#define UltraEco2 34
#define UltraEco3 52
#define UltraEco4 46
#define UltraEco5 36
#define UltraEco6 21
#define UltraEco7 18
#define UltraEco8 A0
#define UltraEco0 000


////define mission_state

#define dm0     31
#define dm1     33
#define dshuttle  29
int m0,m1,m2,first_hadf_flag ;

// back ultra sensors 4 near motor 4 & 2 near ...


/* Array of class Ultrasonic
   Timeout is 6000 us = 103 cm */
Ultrasonic ultrasonic[10] = {
  {UltraTrig0, UltraEco0, 20000},
  {UltraTrig1, UltraEco1, 20000},
  {UltraTrig2, UltraEco2, 20000},
  {UltraTrig3, UltraEco3, 20000},
  {UltraTrig4, UltraEco4, 20000},
  {UltraTrig5, UltraEco5, 20000},
  {UltraTrig6, UltraEco6, 20000},
  {UltraTrig7, UltraEco7, 20000},
  {UltraTrig8, UltraEco8, 20000},
  {UltraTrig9, UltraEco9, 20000},
  };

//to store readings
int cm[10];

/********************************/




/*****serial******/
/* nasr_e true --->  serial (on)
   nasr_e false --> serial (off) */
#define nasr_e true
/********* HADF && TASLEEM INTEGERS*******/
int ch_hadf=0 ;
int ch_shuttle = 0;



void setup() {
  
  //motors pins
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(flash_pin,OUTPUT);
  
  pinMode(dproximityR,INPUT);
  pinMode(dproximityL,INPUT);
  pinMode(dproximitySh,INPUT);
  //    mission state
  pinMode(m0, INPUT);
  pinMode(m1, INPUT);
  pinMode(dshuttle, INPUT);
  m0=digitalRead(dm0);
  m1=digitalRead(dm1);
  m2=digitalRead(dshuttle);


  
  
  //solenoid pins
  pinMode(sol, OUTPUT);
  pinMode(val3, OUTPUT);
  pinMode(val4, OUTPUT);
  pinMode(val5, OUTPUT); 
  pinMode(vent,OUTPUT);


  //turn the PID on
  PID_MR.SetMode(AUTOMATIC);
  PID_MR.SetSampleTime(100);
  PID_MR.SetOutputLimits(-120, 120);
  
  //turn the PID on
  PID_F.SetMode(AUTOMATIC);
  PID_F.SetSampleTime(100);
  PID_F.SetOutputLimits(-120, 120);

  //turn the PID on
  PID_Fr.SetMode(AUTOMATIC);
  PID_Fr.SetSampleTime(100);
  PID_Fr.SetOutputLimits(-120, 120);
  
  //turn the PID on
  PID_B.SetMode(AUTOMATIC);
  PID_B.SetSampleTime(100);
  PID_B.SetOutputLimits(-120, 120);

  ///turn the pid on
  PID_start.SetMode(AUTOMATIC);
  PID_start.SetSampleTime(100);
  PID_start.SetOutputLimits(-120, 120);

  //enable serial
  #if nasr_e
    Serial.begin(115200);
  #endif


  /****************SHUTTLE & MISSION STATE *********************/
  

/// checking mission state && DOING MISSION
  /*if (m2 ==HIGH && m0 ==LOW && m1 ==LOW)
  {
    zone1();
  }
  else if (m2 ==LOW && m0 ==HIGH && m1==LOW)
  {
   zone2 ();
  }
  else if (m2 ==LOW && m0 ==LOW &&m1==HIGH)
  {
   zone3 ();
  }*/



/////test

m0=0;m1=0;m2=0 ;
//getShuttlecock1();

zone1();


 //end test 
 
}

void loop() {

  /* m0=digitalRead(dm0);
  m1=digitalRead(dm1);
  shuttle_initial_state=digitalRead(dshuttle);*/

 /*delay(5000);
digitalWrite(val5,HIGH);
 delay(1000);
 digitalWrite(sol5,HIGH);
 delay(2000);
 digitalWrite(sol5,LOW);
 digitalWrite(val5,LOW); */

/*bar3();
initial();
delay(4000);
bar4();
initial();
delay(4000);
bar5();
initial();
delay(4000);*/
//junc();
  //read_ultra();
// follow_forward_start ();
 //junc();
 //start_flash();
// bar5();
// stop_flash();

  //forward_nopid();
  //read_ultra ();

/*****test code******/
 //follow_right_byf ();
 //follow_right_byb ();
 //follow_left_byf ();
 //follow_left_byb ();
 //follow_forward_byl ();
 //follow_forward_byr ();
 //follow_backward_byl ();
 //follow_backward_byr ();
  
  #if nasr_e
    serial_fn();
  #endif 
}
