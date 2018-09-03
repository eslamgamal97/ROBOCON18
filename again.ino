#include <PS2X_lib.h>

#define PS2_DAT        47    
#define PS2_CMD        49
#define PS2_SEL        51
#define PS2_CLK        53

/******************************************************************
 * select modes of PS2 controller:
 *   - pressures = analog reading of push-butttons 
 *   - rumble    = motor rumbling
 * uncomment 1 of the lines for each mode selection
 ******************************************************************/
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you connect the controller, 
//or call config_gamepad(pins) again after connecting the controller.

int error = 0;
byte type = 0;
byte vibrate = 0;

#define go_forward HIGH
#define go_backward LOW

/*//defining direction high for forward
#define dir1 12 //up left
#define dir2 10 //down right
#define dir3 7 //up right
#define dir4 4 //down left
//definining switch high for open
#define pwm1 13
#define pwm2 11
#define pwm3 6
#define pwm4 5*/

//defining direction high for forward
#define dir1 26 //up left
#define dir2 24 //down right
#define dir3 28 //up right
#define dir4 44 //down left
//definining switch high for open
#define pwm1 2
#define pwm2 3
#define pwm3 4
#define pwm4 6

uint16_t val = 254;

bool s1_flag=0,s2_flag=0,s3_flag=0;
#define gripper1 A8
#define gripper2 A9
#define gripper3 A10

#define nasr_e true

void setup(){
  #if nasr_e
    Serial.begin(57600);
  #endif
  
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  
  if(error == 0){
    Serial.print("Found Controller, configured successful ");
    Serial.print("pressures = ");
  if (pressures)
    Serial.println("true ");
  else
    Serial.println("false");
  Serial.print("rumble = ");
  if (rumble)
    Serial.println("true)");
  else
    Serial.println("false");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
  }  
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  
//  Serial.print(ps2x.Analog(1), HEX);
  
  type = ps2x.readType(); 
  switch(type) {
    case 0:
      Serial.print("Unknown Controller type found ");
      break;
    case 1:
      Serial.print("DualShock Controller found ");
      break;
    case 2:
      Serial.print("GuitarHero Controller found ");
      break;
  case 3:
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
   }

  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(pwm4,OUTPUT);

  pinMode(gripper1,OUTPUT);
  pinMode(gripper2,OUTPUT);
  pinMode(gripper3,OUTPUT);
  
  delay(100);
}

void loop(){
  ps_2();
}

