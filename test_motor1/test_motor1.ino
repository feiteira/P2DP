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
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps

  
  stepper1.setMaxSpeed(1200.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  //4076 
  stepper1.moveTo(4076);

  stepper2.setMaxSpeed(1200.0);
  stepper2.setAcceleration(100.0);
  stepper2.setSpeed(200);
  //4076 
  stepper2.moveTo(-4076);



}//--(end setup )---

void loop() {

  //Change direction when the stepper reaches the target position
//  if (stepper1.distanceToGo() == 0) {
//    stepper1.moveTo(-stepper1.currentPosition());
//  }
  stepper1.run();
  stepper2.run();
 // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }
}
