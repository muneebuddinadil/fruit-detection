/******************************THREAD HEADER****************************/
#include <Cth.h>

#include <Servo.h>

Servo openclose_servo;
Servo rotate_servo;
Servo updown_servo;

String inChar;

int servo_position = 0;


int rotatebit = 0;


/******************* INTIAL oF ROTATION SERVO POSTIION *******************/
int rightleftinitservoangle = 180;
int maxrotateangle = 130;
int rlservo_position;



/******************* UP DOWN SERVO POSTIIONS *******************/
int downmaxvalue = 180;
int upmaxvalue = 160;

/************************ OPEN CLOSE SERVO POSITION ****************/
int openvalue = 60;
int closevalue = 120;


void setup() {

  Serial.begin(9600);
  Serial.setTimeout(100);
  setservos_intialPositions();
  Scheduler.startLoop(rotationloop);
  delay(500);
}

void loop() {

  if (Serial.available() > 0) {
    Serial.println("SERIAL AVAILABLE"); Serial.flush();
    inChar = Serial.readString();
    Serial.println("SERIAL DATA"); Serial.println(inChar); Serial.flush();
    int recvalue = inChar.toInt();
    if (recvalue == 1) {
      Serial.println("1  RECEIVED ");
      if (rotatebit == 0) {
        rotatebit = 1;
        stoprotateloop();
        delay(500);
        movetoorange();
      }
    }
    else  if (recvalue == 2) {
      Serial.println("2  RECEIVED ");
      if (rotatebit == 0) {
        rotatebit = 1;
        stoprotateloop();
        delay(500);
        movetoapple();
      }
    }

    else  if (recvalue == 3) {
      Serial.println("3  RECEIVED ");
      if (rotatebit == 0) {
        rotatebit = 1;
        stoprotateloop();
        delay(500);
        movetobanana();
      }
    }
  
    else   if (recvalue == 0) {
      Serial.println("0  RECEIVED ");
      if (rotatebit == 1) {
        rotatebit = 0;
        setservos_intialPositions();
      }
    }
  }

  Scheduler.delay(300);
}

void rotationloop() {
  if (rotatebit == 0) {
    Serial.println("-------- ROATATE SERVO CALLED -------------");
    rotateservo();
  }

  Scheduler.delay(30);
}

void setservos_intialPositions() {
  openm4();
  delay(1000);
  intialpositionofrotationservo();
  delay(1000);
  updownservointialposition();
}


void rotateservo() {
  rotatetorightfrominit();
  delay(1000);
  rotatefromrighttoleft();
  delay(1000);
}


void upanddownaction() {
  downservofromintial();
  delay(1000);
  upservofromintial();
  delay(1000);
}


void movetoorange() {
  downservofromintial();
  delay(1000);
  closem4();
  delay(1000);
  upservofromintial();
  delay(1000);
  movetoplaceorange();
  delay(1000);
  downservofromintial();
  delay(1000);
  openm4();
  delay(1000);
  upservofromintial();
  delay(1000);
  rotatebit=0;
}

void movetoapple() {
  downservofromintial();
  delay(1000);
  closem4();
  delay(1000);
  upservofromintial();
  delay(1000);
  movetoplaceapple();
  delay(1000);
  downservofromintial();
  delay(1000);
  openm4();
  delay(1000);
  upservofromintial();
  delay(1000);
  rotatebit=0;
}

void movetobanana() {
  downservofromintial();
  delay(1000);
  closem4();
  delay(1000);
  upservofromintial();
  delay(1000);
  movetoplacebanana();
  delay(1000);
  downservofromintial();
  delay(1000);
  openm4();
  delay(1000);
  upservofromintial();
  delay(1000);
  rotatebit=0;
}
