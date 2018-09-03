void zone2()
{
   
  read_ultra() ;
  

  while (abs(cm[4] - cm[5]) > 7) ///rotate until  auto is parallel to back wall
  {
    val = 100;
    turning_left() ;
    //if (val > max_speed)
    // val = max_speed ;
  }

   while (cm[4] <50 && cm[5] <50) ///rotate until  auto is parallel to back wall   note 1
  {
    val = 150;
    forward_nopid() ;

  }
  while (cm[6] <120 || cm[7] <120)
  {
     follow_right_byb () ;
  }
   while ( cm[4] <80 && cm[5] <80 ) {
    val = 100 ;
    forward_nopid ();
  }

  stoppo();
erg3_z2:  // lw hadaf z2 wrong yrg3 y7df tany




 
    getShuttle_z1();
   

  digitalWrite(grip,LOW);  //CLOSE GRIPPER


  while ( cm[2] > 130 || cm[3] > 130 ) {
    val = 254 ;
    forward_nopid ();
  }

  while (cm[4] < 270 || cm[5] < 270 )
  {
    follow_forward_byl ();
  }
  
  /*while (proximityR == true || proximityL == true){
    val = 100;
    forward_nopid();
    junc();
  }*/

  while (cm[2] >15 || cm[3] >15)
  {
    val=100;
    moving_left_nopid() ;
  }

  /* while (cm[3] >cm[2])
  {
    val=100;
    turning_right();
  }*/
  
  while (cm[2] >cm[3])
  {
    val=100;
    turning_left();
  }

    proximityL = digitalRead (dproximityL);
   while ( proximityL == true && cm[4] < 330 && cm[5] < 330 ){
    val = 100;
    forward_nopid();
   proximityL = digitalRead (dproximityL);

    
  }
    val=90 ;
    turning_right();
    delay(100);
  stoppo();
  //// missing code
  start_flash();
  bar4();
  stop_flash();

while ( cm[2] < 120 &&  cm[3] < 120 ) {
    val = 254 ;
    follow_backward_byl ();
  }

  
  while ( cm[2] < 100 &&  cm[3] > 120 ) {
    val = 254;
    backward_nopid();
  }
  stoppo();
    ch_hadf = checkHadf_z1();
  if (ch_hadf ==1)
  {
    goto erg3_z2;
    ch_hadf = 0;
  }
  else 
  {
  stoppo();
  while(1);
  }












  getShuttle_z1();
  while ( cm[2] > 130 || cm[3] > 130 ) {
    val = 254 ;
    forward_nopid ();
  }

  while (proximityL == true)
  {
    val = 120;
    follow_forward_start ();
  }
  
  /*while (proximityR == true || proximityL == true){
    val = 100;
    forward_nopid();
    junc();
  }*/
  stoppo();
  while (cm[2] >7 || cm[3] >7)
  {
    val=100;
    moving_left_nopid() ;
  }

  
  while (cm[3] >cm[2])
  {
    val=100;
    turning_right();
  }
  stoppo();

  ///missing code
  start_flash();
  bar4();
  stop_flash();

  while ( cm[2] < 100 &&  cm[3] < 100 ) {
    follow_backward_byl ();
  }
  while ( cm[2] < 100 &&  cm[3] > 100 ) {
    backward_nopid ();
  }
  
  ch_hadf = checkHadf_z1();
  if (ch_hadf)
  {
    goto erg3_z2;
    ch_hadf = 0;
  }
  else 
  {
  stoppo();
  while(1);
  }
}

