void check_bultra(){
  read_ultra();
  if (cm[9] >10 )
  {
    stoppo();
  }
  

  
}

void checkShuttlecock()
{
  // checking the condition 
  proximitySh = digitalRead (dproximitySh); // Read and Save the o/p
  if (proximitySh == false) // the shuttle is normal
  {
    // HOLD the shuttle
   // Enter zone 2
  }
  else 
  {
    //Hold the shuttle
    
    // Enter zone 2
    
  }     
}
int checkHadf_z1() {  ////check if throw in zone 1 is correct
  
  read_ultra();
  
  if (cm[6] <= 80 || cm[7] <= 80)
    ch_hadf = 1;
    
  else 
    ch_hadf = 0;
    
  return ch_hadf;
}



void getShuttle_z1() { 
  read_ultra() ;     //receive shuttle from manual at zone 1
  while ( cm[6] >= 80 && cm[7] >= 80) {
    
    stoppo();
    Serial.println("manual isn't detected");
  }
  while (cm[6] < 80 || cm[7] < 80) {
    stoppo();
    Serial.println("manual is detected");
  }
}

void getShuttle_z2() {    //receive shuttle from manual at zone 1
  
  while ( cm[6] < 80 || cm[7] < 80 ) {
    Serial.println("manual is detected");
    stoppo() ;
  }
  
}

void getShuttle_z3() {    //receive shuttle from manual at zone 1
  
  while ( cm[6] > 80 && cm[7] > 80 ) {
    Serial.println("manual isn't detected");
    stoppo();
  }
  
  while ( cm[6] < 80 || cm[7] < 80 ) {
    Serial.println("manual is detected");
    stoppo() ;
  }
  
}

///*** fn for test

void hadf()
{
  stoppo();
  delay(2000);
}
void taslem()
{
  stoppo();
  delay(2000);
}
void check_taslem()
{
  stoppo();
  delay(2000);
}



