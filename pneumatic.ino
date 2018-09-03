void s1()
{
  s1_flag = !s1_flag;
  digitalWrite(gripper1,s1_flag);
  #if nasr_e
    Serial.print("s1 is ");
    s1_flag? Serial.println("open"):Serial.println("closed");
  #endif
}

void s2()
{
  s2_flag = !s2_flag;
  digitalWrite(gripper2,s2_flag);
  #if nasr_e
    Serial.print("s2 is ");
    s2_flag? Serial.println("open"):Serial.println("closed");
  #endif
}

void s3()
{
  s3_flag = !s3_flag;
  digitalWrite(gripper3,s3_flag);
  #if nasr_e
    Serial.print("s3 is ");
    s3_flag? Serial.println("open"):Serial.println("closed");
  #endif
}
