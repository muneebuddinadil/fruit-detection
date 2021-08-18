// code for arm base rotation

int rotateservo_position = 100;


int orangeplaceangle=0;
int appleplaceangle=40;
int bananaplaceangle=80;


int maxrightposition=60;
int stopservoangle;


void intialpositionofrotationservo(){
  Serial.println("-------- ROTATE SERVO INTITAL POSIITON--------------");
  rotate_servo.attach (7);
  delay(20);
  rotate_servo.write(rightleftinitservoangle);
  delay(20);
  rotate_servo.detach();
}


void rotatetorightfrominit(){
 if (rotatebit == 0) {
  rotate_servo.attach (7);
  
  for (rlservo_position = rightleftinitservoangle; rlservo_position >=maxrotateangle; rlservo_position -= 1) {
     if (rotatebit == 0) {
    
    Serial.print(" RIGHT POSITION:"); Serial.println(rlservo_position);
    rotate_servo.write(rlservo_position);
    stopservoangle = rlservo_position;
     Serial.print(" /// STOP SERVO ANGLE POSITION:"); Serial.println(stopservoangle);
    //delay(500);
    Scheduler.delay(500);
     }
  }

  rotate_servo.detach();
  
 }

}


void rotatefromrighttoleft(){
    
     if (rotatebit == 0) {
    
    rotate_servo.attach (7);
  
  for (rlservo_position = maxrotateangle;rlservo_position <= rightleftinitservoangle;rlservo_position += 1) {
 
     if (rotatebit == 0) {
    Serial.print(" RIGHT TO  LEFT  POSITION:"); Serial.println(rlservo_position);
       rotate_servo.write(rlservo_position);
           stopservoangle = rlservo_position;
     Serial.print(" ===== STOP SERVO ANGLE POSITION:"); Serial.println(stopservoangle);
      Scheduler.delay(500);
     }
  }

  rotate_servo.detach();
     }
}


void stoprotateloop(){
  Serial.println("-------- STOP ROTATE SERVO --------------");
  Serial.print(" -------------- STOP SERVO ANGLE POSITION:"); Serial.println(stopservoangle);
  rotate_servo.attach (7);
  delay(200);
  rotate_servo.write(stopservoangle);
  delay(200);
  rotate_servo.detach();
 Serial.print(" STOP SERVO POSITION:"); Serial.println(stopservoangle);
   
}

void movetoplaceapple(){

   rotate_servo.attach (7);
  
  for (servo_position = stopservoangle; servo_position >=appleplaceangle; servo_position -= 1) {
    Serial.print(" MOVING TO APPLE PLACE POSITION POSITION:"); Serial.println(servo_position);
    rotate_servo.write(servo_position);
    Scheduler.delay(500);
  }

  rotate_servo.detach();

 
//  rotate_servo.attach (7);
//  delay(200);
//  rotate_servo.write(appleplaceangle);
//  delay(200);
//  rotate_servo.detach();
}


void movetoplaceorange(){

   rotate_servo.attach (7);
  
  for (servo_position = stopservoangle; servo_position >=orangeplaceangle; servo_position -= 1) {
    Serial.print(" MOVING TO ORANGE POSITION POSITION:"); Serial.println(servo_position);
    rotate_servo.write(servo_position);
    Scheduler.delay(500);
  }

  rotate_servo.detach();

 
//  rotate_servo.attach (7);
//  delay(200);
//  rotate_servo.write(orangeplaceangle);
//  delay(200);
//  rotate_servo.detach();
}


void movetoplacebanana(){

   rotate_servo.attach (7);
  
  for (servo_position = stopservoangle; servo_position >= bananaplaceangle; servo_position -= 1) {
    Serial.print(" MOVING TO BANANA POSITION POSITION:"); Serial.println(servo_position);
    rotate_servo.write(servo_position);
    Scheduler.delay(500);
  }

  rotate_servo.detach();

 
//  rotate_servo.attach (7);
//  delay(200);
//  rotate_servo.write(bananaplaceangle);
//  delay(200);
//  rotate_servo.detach();
}
