void read_ultra (){
   /* Ranging(1) for CM
     Ranging(0) for inch */
  for (byte i = 0; i < 10; i++)
    cm[i] = ultrasonic[i].Ranging(1);
  }

//MOVING  FORWARD  PID by   left  sensor cm[2](odam) & cm[3](warah)
void forward() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, LMS_F - 10);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, LMS_F - 10);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, RMS_F);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, RMS_F);

  #if nasr_e
    Serial.println("forward");
  #endif
}



//MOVING   FORWARD   PID by   right  sensor cm[7](odam) &cm[6] (warah)
void forward_r() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, LMS_Fr - 10);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, LMS_Fr - 10);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, RMS_Fr);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, RMS_Fr);

  #if nasr_e
    Serial.println("forward");
  #endif
}



//MOVING   BACKWARD  PID by   left    sensor cm[2](odam) & cm[3](warah)
void backward() {

  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, RMS_F - 5);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, RMS_F - 5);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, LMS_F);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, LMS_F);
  
  #if nasr_e
    Serial.println("backward");
  #endif
}



//MOVING    BACKWARD   PID by   right   sensor cm[7](odam) &cm[6] (warah)
void backward_r() {
  
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, RMS_Fr - 5);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, RMS_Fr - 5);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, LMS_Fr);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, LMS_Fr);
  
  #if nasr_e
    Serial.println("backward");
  #endif
}




// MOVING     LEFT   PID by     forward    sensor cm[8](odam) & cm[1](warah)
void moving_left() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, LMS_MR);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, RMS_MR);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, LMS_MR);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, RMS_MR);
  
  #if nasr_e
    Serial.println("moving left");
  #endif
}


// MOVING     LEFT     PID by     backward     sensor cm[5](odam) & cm[4](warah)
void moving_left_r() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, LMS_B);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, RMS_B);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, LMS_B);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, RMS_B);
  
  #if nasr_e
    Serial.println("moving LEFT");
  #endif
}



// MOVING     RIGHT    PID by     forward     sensor cm[8](odam) & cm[1](warah)
void moving_right() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, RMS_MR - 15);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, LMS_MR - 40);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, RMS_MR - 50);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, LMS_MR - 5);
  
  #if nasr_e
    Serial.println("moving right");
  #endif
}

// MOVING     RIGHT    PID by     backward     sensor cm[5](odam) & cm[4](warah)
void moving_right_r() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, RMS_B - 15);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, LMS_B - 40);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, RMS_B - 50);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, LMS_B - 5);
  
  #if nasr_e
    Serial.println("moving right");
  #endif
}
///   MOVING RIGHT FOR START
// cm[5](odam) & cm[4](BACK)
void forward_start() {
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, LMS_start );
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, LMS_start );
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, RMS_start);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, RMS_start);

  #if nasr_e
    Serial.println("forward_start");
  #endif
}






//MOVING FORWARD without PID
void forward_nopid() {
  //ultra reedings
  read_ultra ();
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, val-10);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, val-10);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, val);


  #if nasr_e
    Serial.println("forward nopid");
  #endif
}

//MOVING BACKWARD without PID
void backward_nopid() {
  //read ultrasonic
  read_ultra ();
  
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, val -5);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, val - 5);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, val);

  #if nasr_e
    Serial.println("backward");
  #endif
}



// MOVING RIGHT without PID
void moving_right_nopid() {
  //read ultrasonic
  read_ultra ();
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, val - 15);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, val - 40);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, val - 50);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, val - 5);
  #if nasr_e
    Serial.println("moving right");
  #endif
}


// MOVING LEFT without PID
void moving_left_nopid() {
  //read ultrasonic
  read_ultra ();
  
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, val);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, val);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, val);
  
  #if nasr_e
    Serial.println("moving left");
  #endif
}


//rotating left
void turning_left() {
   //read ultrasonic
  read_ultra ();
  
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, val);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, val);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, val);

  #if nasr_e
    Serial.println("turning left");
  #endif
}


//rotating right
void turning_right() {
  //read ultrasonic
  read_ultra ();
  
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, val);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, val);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, val);

  #if nasr_e
    Serial.println("turning right");
  #endif
}
void stoppo() {
  //read ultrasonic
  read_ultra ();
  
  analogWrite(dir1, 0);
  analogWrite(pwm1, 0);
  analogWrite(dir2, 0);
  analogWrite(pwm2, 0);
  analogWrite(dir3, 0);
  analogWrite(pwm3, 0);
  analogWrite(dir4, 0);
  analogWrite(pwm4, 0);

  #if nasr_e
    Serial.println("stop");
  #endif
}



