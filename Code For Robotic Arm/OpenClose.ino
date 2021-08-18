//Code for Gripper to pick and place objects (fruits)

void openm4() {
Serial.println("--------------OPEN PICKER ---------------------");
  openclose_servo.attach (4);
  delay(500);
   openclose_servo.write(openvalue);
delay(500);
  openclose_servo.detach();
}

void closem4() {
Serial.println("-------------- CLOSE PICKER ---------------------");
  openclose_servo.attach (4);
  for (servo_position = openvalue; servo_position <= closevalue; servo_position += 1) {

    openclose_servo.write(servo_position);
   // delay(10);
     Scheduler.delay(100);
  }

 openclose_servo.detach();

//   openclose_servo.attach (4);
//  delay(500);
//   openclose_servo.write(130);
//   delay(500);
//  openclose_servo.detach();
}
