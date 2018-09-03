void bar3()
{
 digitalWrite(val3,HIGH);
 delay(1000);
 digitalWrite(sol,HIGH);
 delay(2000);
 digitalWrite(sol,LOW);
 digitalWrite(val3,LOW);
}

void bar4()
{
 digitalWrite(val4,HIGH);
 delay(1000);
 digitalWrite(sol,HIGH);
 delay(2000);
 digitalWrite(sol,LOW);
 digitalWrite(val4,LOW);
}

void bar5()
{
 digitalWrite(val5,HIGH);
 delay(1000);
 digitalWrite(sol,HIGH);
 delay(2000);
 digitalWrite(sol,LOW);
 digitalWrite(val5,LOW);
}


void initial()
{
  //on 3 bar
  digitalWrite(sol,LOW);
  digitalWrite(val3,LOW);
  digitalWrite(val4,LOW);
  digitalWrite(val5,LOW);
}
