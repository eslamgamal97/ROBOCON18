void second_try()
{
  read_ultra() ;

  while (abs(cm[4] - cm[5]) > 10) ///rotate until  auto is parallel to back wall
  {
    val = 100;
    turning_left() ;
    //if (val > max_speed)
    // val = max_speed ;
  }

  while ( cm[1] > 120 || cm[8] > 120) {
    val = 100;
    //follow_right_start ();
  }
  while ( cm[6] > 100 &&  cm[7] > 100 ) {
    val = 254 ;
    follow_right_byb () ;

  }

erg3_z2:// lw hadaf z2 wrong yrg3 y7df tany
  if (first_hadf_flag == 0) {
   getShuttle_z2();
  }
  while ( cm[4] < 330 &&  cm[5] < 330 ) {
    follow_forward_byr ();

  }
  ///missing code
  hadf();

  while ( cm[2] < 100 &&  cm[3] < 100 ) {
    follow_backward_byr ();
  }
  while ( cm[2] < 100 &&  cm[3] > 100 ) {
    backward_nopid ();
  }
  
  getShuttle_z2();
  // ch_shuttle = checkShuttle();
  if (ch_shuttle) //0
  {
    goto erg3_z2  ;
  }

erg3_z3:    // lw hadaf z3 wrong yrg3 y7df tany
  while ( cm[1] > 140 &&  cm[8] > 140 ) {
    follow_forward_byr ();
  }
  hadf() ;
  while ( cm[2] < 100 &&  cm[3] < 100 ) {
    follow_backward_byr ();
  }
  while ( cm[2] < 100 &&  cm[3] > 100 ) {
    backward_nopid ();
  }
  getShuttle_z2();
  goto erg3_z3 ;
}
