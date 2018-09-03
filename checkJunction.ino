void junc()
{
  // checking the condition
  proximityR = digitalRead (dproximityR); //Read and Save the o/p
  proximityL = digitalRead (dproximityL);
  if (proximityR == true && proximityL == false){
    turning_left();
  }
  else if (proximityR == false && proximityL == true){
    turning_right();
  }
  else if (proximityR == false && proximityL == false) // see a junction
  {
   stoppo(); //Stop the robot at the junction: Note that the robot might stop after the junction
   //operate the PNEUMATIC system 
   //Set the PNEUMATIC system  to intial conditions
  }
  
 
}
