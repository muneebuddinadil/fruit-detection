
void updownservointialposition() {
  updown_servo.attach (5);
  delay(1000);
  updown_servo.write(upmaxvalue);
  delay(1000);
  updown_servo.detach();
}


void downservofromintial(){
  updown_servo.attach (5);
  delay(1000);
 // updown_servo.write(upmaxvalue);
   for (servo_position = upmaxvalue; servo_position  <= downmaxvalue; servo_position += 1) {
    Serial.print("UP DOWN SERVO POSITION:"); Serial.println(servo_position);
    updown_servo.write(servo_position);
    delay(200);
  }
  delay(1000);
 // updown_servo.detach();
}



void upservofromintial(){
  updown_servo.attach (5);
  delay(1000);
 // updown_servo.write(upmaxvalue);
   for (servo_position = downmaxvalue; servo_position >= upmaxvalue; servo_position -= 1) {
    Serial.print("UP DOWN SERVO POSITION:"); Serial.println(servo_position);
    updown_servo.write(servo_position);
    delay(200);
  }
  delay(1000);
  updown_servo.detach();
}
