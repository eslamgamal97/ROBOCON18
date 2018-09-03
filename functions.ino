void moving_right() {
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, val-5 );
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, val-5 );
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, val - 10);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, val - 10);

  #if nasr_e
    Serial.println("forward");
  #endif
}

void moving_left() {
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, val  );
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, val  );
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, val - 10);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, val);
  
  #if nasr_e
    Serial.println("backward");
  #endif
}

void backward() {
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, val - 45);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, val);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, val - 10);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, val - 25);
  
  #if nasr_e
    Serial.println("moving left");
  #endif
}

void forward() {
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, val - 25);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, val - 50);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, val - 30);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, val - 10);
  
  #if nasr_e
    Serial.println("moving right");
  #endif
}

void turning_left() {
  digitalWrite(dir1, go_backward);
  analogWrite(pwm1, val);
  digitalWrite(dir2, go_backward);
  analogWrite(pwm2, val);
  digitalWrite(dir3, go_forward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_forward);
  analogWrite(pwm4, val);

  #if nasr_e
    Serial.println("turning left");
  #endif
}

void turning_right() {
  digitalWrite(dir1, go_forward);
  analogWrite(pwm1, val);
  digitalWrite(dir2, go_forward);
  analogWrite(pwm2, val);
  digitalWrite(dir3, go_backward);
  analogWrite(pwm3, val);
  digitalWrite(dir4, go_backward);
  analogWrite(pwm4, val);

  #if nasr_e
    Serial.println("turning right");
  #endif
}

void stoppo() {
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  analogWrite(pwm3, 0);
  analogWrite(pwm4, 0);

  #if nasr_e
    Serial.println("stop");
  #endif
}
