void ps_2(){
  ps2x.read_gamepad();

  if(ps2x.Button(PSB_PAD_UP)){
    forward();
  }
  if (ps2x.Button(PSB_PAD_RIGHT)){
    moving_right();
  }
  if (ps2x.Button(PSB_PAD_DOWN)){
    backward();
  }
  if (ps2x.Button(PSB_PAD_LEFT)){
    moving_left();
  }

  if (ps2x.ButtonPressed(PSB_TRIANGLE))
  {
    if (s1_flag || s2_flag || s3_flag)
    {
      if (s1_flag)
        s1();
      if (s2_flag)
        s2();
      if (s3_flag)
        s3();
    }
    else
    {
      s1();
      s2();
      s3();
    }
  }

    if (ps2x.ButtonPressed(PSB_CROSS))
    s2(); 
    
   if (ps2x.ButtonPressed(PSB_SQUARE))
    s1();

  if (ps2x.ButtonPressed(PSB_CIRCLE))
    s3();
   if (ps2x.Button(PSB_L2)){
    val = val - 5;
    val = constrain(val,125,254);
    #if nasr_e
      Serial.println("speed down ");
      Serial.print("val = ");
      Serial.println(val);
    #endif
  }
  if (ps2x.Button(PSB_R2)){
    val = val + 5;
    val = constrain(val,125,254);
    #if nasr_e
      Serial.println("speed up ");
      Serial.print("val = ");
      Serial.println(val);
    #endif
  } 
   if (ps2x.Button(PSB_L1)){
    turning_left();
  }
   if (ps2x.Button(PSB_R1)){
    turning_right();
  }
  if (!(ps2x.Button(PSB_R1) || ps2x.Button(PSB_L1) || ps2x.Button(PSB_R2)|| ps2x.Button(PSB_L2) ||ps2x.ButtonPressed(PSB_TRIANGLE)||ps2x.ButtonPressed(PSB_CIRCLE) ||ps2x.ButtonPressed(PSB_CROSS)||ps2x.ButtonPressed(PSB_SQUARE)||ps2x.Button(PSB_PAD_LEFT)||ps2x.Button(PSB_PAD_DOWN)||ps2x.Button(PSB_PAD_RIGHT)||ps2x.Button(PSB_PAD_UP))){
    stoppo();
  }
  
 delay(50);
}
