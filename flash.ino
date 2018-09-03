
void flash()
{
  flash_state = !flash_state;
  digitalWrite(flash_pin,flash_state);
}
void start_flash()
{
  Timer1.initialize(100000);      // initialize timer1, and set a 1/2 second period
  Timer1.attachInterrupt(flash);  // attaches callback() as a timer overflow interrupt
}

void stop_flash()
{
  Timer1.stop();
  flash_state = 0;
  digitalWrite(flash_pin,LOW);
}


/*void flashhh () {
  while (val3==HIGH || val4==HIGH || val5==HIGH){
   x=millis();
  blink();
  if (millis()-x>
    }
  
  }*/
