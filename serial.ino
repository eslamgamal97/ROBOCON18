void serial_fn()
{
  //Printing the values on serial
  Serial.println(" ULTRSONIC values");
  Serial.print(" ULTRA0= ");
  Serial.println(cm[0]);
  Serial.print(" ULTRA1= ");
  Serial.println(cm[1]);
  Serial.print(" ULTRA2= ");
  Serial.println(cm[2]);
  Serial.print(" ULTRA3= ");
  Serial.println(cm[3]);
  Serial.print(" ULTRA4= ");
  Serial.println(cm[4]); 
  Serial.print(" ULTRA5= ");
  Serial.println(cm[5]);
  Serial.print(" ULTRA6= ");
  Serial.println(cm[6]);
  Serial.print(" ULTRA7= ");
  Serial.println(cm[7]);
  Serial.print(" ULTRA8= ");
  Serial.println(cm[8]);
  Serial.print(" ULTRA9= ");
  Serial.println(cm[9]); 
  Serial.println("proximityR = ");
  Serial.print(proximityR);
  Serial.println("proximityL = ");
  Serial.print(proximityL);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print("m0 is =");
  Serial.println(m0);
  Serial.print("m1 is =");
  Serial.println(m1);
  Serial.print("m2 =");
  Serial.println(m2);

      /*
  Serial.println("PID values");
  Serial.println();
  Serial.println();
  
  Serial.println("//MOVING FORWARD PID by left sensor cm[2](odam) & cm[3](warah) values");
  Serial.print(" INPUT_f= ");
  Serial.println(Input_f);
  Serial.print(" OUTPUT_f= ");
  Serial.println(Output_f);
  Serial.print(" LMS_F=");
  Serial.println(LMS_F);
  Serial.print(" RMS_F= ");
  Serial.println(RMS_F);
  Serial.println();
  Serial.println();

  
  Serial.println("//MOVING FORWARD PID by right sensor cm[7](odam) &cm[6] (warah) values");
  Serial.print(" INPUT_f= ");
  Serial.println(Input_fr);
  Serial.print(" OUTPUT_f= ");
  Serial.println(Output_fr);
  Serial.print(" LMS_F=");
  Serial.println(LMS_Fr);
  Serial.print(" RMS_F= ");
  Serial.println(RMS_Fr);
  Serial.println();
  Serial.println();
  
  
  Serial.println("//MOVING RIGHT PID by forward sensor cm[8](odam) & cm[1](warah) values");
  Serial.print(" INPUT_mr=");
  Serial.println(Input_mr);
  Serial.print(" OUTPUT_mr=");
  Serial.println(Output_mr);
  Serial.print(" LMS_MR=");
  Serial.println(LMS_MR);
  Serial.print(" RMS_MR=");
  Serial.println(RMS_MR);
  Serial.println();
  Serial.println();
  

  Serial.println("//MOVING RIGHT PID by backward sensor cm[5](odam) & cm[4](warah) values");
  Serial.print(" INPUT_mr=");
  Serial.println(Input_b);
  Serial.print(" OUTPUT_mr=");
  Serial.println(Output_b);
  Serial.print(" LMS_MR=");
  Serial.println(LMS_B);
  Serial.print(" RMS_MR=");
  Serial.println(RMS_B);
  Serial.println();
  Serial.println();




  Serial.print(" Stage= ");
  Serial.println(stage);
  Serial.print(" val=");
  Serial.println(val);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print(" m0= ");
  Serial.println(stage);
  Serial.print(" m1= ");
  Serial.println(stage);
  Serial.print(" Shuttle ");
  Serial.println(shuttle);*/
  //delay(500);
}
