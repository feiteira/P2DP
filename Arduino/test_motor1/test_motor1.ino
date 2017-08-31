#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motor1Pin1  3     // IN1 on the ULN2003 driver 1
#define motor1Pin2  4     // IN2 on the ULN2003 driver 1
#define motor1Pin3  5     // IN3 on the ULN2003 driver 1
#define motor1Pin4  6     // IN4 on the ULN2003 driver 1

#define motor2Pin1  8     // IN1 on the ULN2003 driver 1
#define motor2Pin2  9     // IN2 on the ULN2003 driver 1
#define motor2Pin3 10     // IN3 on the ULN2003 driver 1
#define motor2Pin4 11     // IN4 on the ULN2003 driver 1


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);
AccelStepper stepper2(HALFSTEP, motor2Pin1, motor2Pin3, motor2Pin2, motor2Pin4);

int incomingByte = 0;   // for incoming serial data


void setup() {
        Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps

  
  stepper1.setMaxSpeed(1200.0);
  stepper1.setAcceleration(200.0);
  stepper1.setSpeed(400);
  //4076 
 // stepper1.moveTo(4076);

  stepper2.setMaxSpeed(1200.0);
  stepper2.setAcceleration(200.0);
  stepper2.setSpeed(400);
  //4076 
 // stepper2.moveTo(-4076);



}//--(end setup )---

void processSerial(){
  // send data only when you receive data:
  if (Serial.available() > 0) {
     // read the incoming byte:
     incomingByte = Serial.read();
     // say what you got:
     Serial.print("I received: ");
     Serial.println(incomingByte, DEC);
    stepper1.moveTo(incomingByte);
    stepper2.moveTo(-incomingByte);

 
   }
}

void loop() {

  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() != 0) {
    //  Serial.print("Stepper 1: ");
    Serial.print(stepper1.distanceToGo(), DEC);
    //  Serial.print("\tStepper 2: ");
    Serial.println(stepper2.distanceToGo(), DEC);
    //    stepper1.moveTo(-stepper1.currentPosition());
  }else{
    String str = Serial.readStringUntil("\n");
    if(str.length() != 0){
      int m1, m2;
      sscanf (str.c_str(), "%d %d", &m1, &m2);
      Serial.print(m1, DEC);
       Serial.print(m2, DEC);
      stepper1.moveTo(m1);
      stepper2.moveTo(m2);
    }
  }
  stepper1.run();
  stepper2.run();

 //processSerial();
}
