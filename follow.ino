
// FOLLOWING RIGHT PID by forward sensor cm[8](odam) & cm[1](warah)
void follow_right_byf () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_mr = cm[8] - cm[1];
  PID_MR.Compute();
  //speed calculation and limitation
  RMS_MR = constrain(val + Output_mr, 0, max_speed);
  LMS_MR = constrain(val - Output_mr, 0, max_speed);

    // in case max speed didn't achieved in  soft start
  if (cm[1] >= 30 && cm[1] <= 80  && cm[8] >= 30 && cm[8] <= 80)
  {
     moving_right() ;
  }
  else if ( cm[1] > 80 || cm[8] > 80 )
  {
     forward_nopid() ;
  }
  else if (  cm[1] < 30 || cm[8] < 30 )
  {
     backward_nopid();
  } 
 }





// FOLLOWING LEFT PID by forward sensor cm[8](odam) & cm[1](warah)
void follow_left_byf () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_mr = cm[8] - cm[1];
  PID_MR.Compute();
  //speed calculation and limitation
  RMS_MR = constrain(val + Output_mr, 0, max_speed);
  LMS_MR = constrain(val - Output_mr, 0, max_speed);

    // in case max speed didn't achieved in  soft start
  if (cm[1] >= 30 && cm[1] <= 60  && cm[8] >= 30 && cm[8] <= 60)
  {
     moving_left() ;
  }
  else if ( cm[1] > 60 || cm[8] > 60 )
  {
     forward_nopid() ;
  }
  else if (  cm[1] < 30 || cm[8] < 30 )
  {
     backward_nopid();
  } 
 }







// FOLLOWING FORWARD PID by left sensor cm[2](odam) & cm[3](warah)
void follow_forward_byl () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_f = cm[2] - cm[3];
  PID_F.Compute();
  //speed calculation and limitation
  RMS_F = constrain(val - Output_f, 0, max_speed);
  LMS_F = constrain(val + Output_f, 0, max_speed);

    // in case max speed didn't achieved in  soft start
  if (cm[2] >= 20 && cm[2] <= 50  && cm[3] >= 20 && cm[3] <= 50)
  {
     forward();
  }
  else if ( cm[2] > 50 || cm[3] > 50 )
  {
      moving_left_nopid() ;
  }
  else if (  cm[2] < 20 || cm[3] < 20 )
  {
     moving_right_nopid() ;
  } 
 }



// FOLLOWING BACKWARD PID by left sensor cm[2](odam) & cm[3](warah)
void follow_backward_byl () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_f = cm[2] - cm[3];
  PID_F.Compute();
  //speed calculation and limitation
  RMS_F = constrain(val - Output_f, 0, max_speed);
  LMS_F = constrain(val + Output_f, 0, max_speed);

   // in case max speed didn't achieved in  soft start
  if (cm[2] >= 30 && cm[2] <= 60  && cm[3] >= 30 && cm[3] <= 60)
  {
     backward();
  }
  else if ( cm[2] > 60 || cm[3] > 60 )
  {
      moving_left_nopid() ;
  }
  else if (  cm[2] < 30 || cm[3] < 30 )
  {
     moving_right_nopid() ;
  } 
 }




// FOLLOWING RIGHT PID by backward sensor cm[5](odam) & cm[4](warah)
void follow_right_byb () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_b = cm[4] - cm[5];
  PID_B.Compute();
  //speed calculation and limitation
  RMS_B = constrain(val + Output_b, 0, max_speed);
  LMS_B = constrain(val - Output_b, 0, max_speed);

   // in case max speed didn't achieved in  soft start
  if (cm[4] >= 40 && cm[4] <= 80  && cm[5] >= 40 && cm[5] <= 80)
  {
     moving_right_r() ;
  }
  else if ( cm[4] > 80 || cm[5] > 80 )
  {
     backward_nopid() ;
  }
  else if (  cm[4] < 40 || cm[5] < 40 )
  {
     forward_nopid();
  } 
 }
 



// FOLLOWING LEFT PID by backward sensor cm[5](odam) & cm[4](warah)
void follow_left_byb () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_b = cm[4] - cm[5];
  PID_B.Compute();
  //speed calculation and limitation
  RMS_B = constrain(val + Output_b, 0, max_speed);
  LMS_B = constrain(val - Output_b, 0, max_speed);

     // in case max speed didn't achieved in  soft start
  if (cm[4] >= 30 && cm[4] <= 60  && cm[5] >= 30 && cm[5] <= 60)
  {
     moving_left_r() ;
  }
  else if ( cm[4] > 60 || cm[5] > 60 )
  {
     backward_nopid() ;
  }
  else if (  cm[4] < 30 || cm[5] < 30 )
  {
     forward_nopid;
  } 
 }




// FOLLOWING FORWARD PID by right sensor cm[7](odam) &cm[6] (warah)
void follow_forward_byr () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_fr = cm[6] - cm[7];
  PID_Fr.Compute();
  //speed calculation and limitation
  RMS_Fr = constrain(val - Output_fr, 0, max_speed);
  LMS_Fr = constrain(val + Output_fr, 0, max_speed);

     // in case max speed didn't achieved in  soft start
  if (cm[6] >= 50 && cm[6] <= 120  && cm[7] >= 50 && cm[7] <= 120)
  {
     forward_r();
  }
  else if ( cm[6] > 120 || cm[7] > 120 )
  {
      moving_right_nopid() ;
  }
  else if (  cm[6] < 50 || cm[7] < 50 )
  {
     moving_left_nopid() ;
  } 
 }





// FOLLOWING BACKWARD PID by right sensor cm[7](odam) &cm[6] (warah)
void follow_backward_byr () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_fr = cm[6] - cm[7];
  PID_Fr.Compute();
  //speed calculation and limitation
  RMS_Fr = constrain(val - Output_fr, 0, max_speed);
  LMS_Fr = constrain(val + Output_fr, 0, max_speed);

   // in case max speed didn't achieved in  soft start
  if (cm[6] >= 30 && cm[6] <= 60  && cm[7] >= 30 && cm[7] <= 60)
  {
     backward_r();
  }
  else if ( cm[6] > 60 || cm[7] > 60 )
  {
      moving_right_nopid() ;
  }
  else if (  cm[6] < 30 || cm[7] < 30 )
  {
     moving_left_nopid() ;
  } 
 }

 //***start** FOLLOWING RIGHT PID by backward sensor cm[5](odam) & cm[4](warah)

void follow_forward_start () {
  
  //read ultrasonic
  read_ultra ();
  //pid compute
  Input_f = cm[2] - cm[3];
  PID_start.Compute();
  //speed calculation and limitation
  RMS_start = constrain(val - Output_f, 0, max_speed);
  LMS_start = constrain(val + Output_f, 0, max_speed);

    // in case max speed didn't achieved in  soft start
  if (cm[2] >= 10 && cm[2] <= 50  && cm[3] >= 10 && cm[3] <= 50)
  {
     forward_start();
  }
  else if ( cm[2] > 50 || cm[3] > 50 )
  {
      moving_left_nopid() ;
  }
  else if (  cm[2] < 10 || cm[3] < 10 )
  {
     moving_right_nopid() ;
  } 
 }
