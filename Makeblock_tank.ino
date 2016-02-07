#include <Makeblock.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeUltrasonicSensor ultraSensor3(PORT_3);
MeDCMotor dcMotor1_m(M1);
MeDCMotor dcMotor2_m(M2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  double dist = ultraSensor3.distanceCm();
  if ( dist < 35 ) 
  {
    dcMotor1_m.run(200);
    dcMotor2_m.run(200); //makes turn left - make both negative to turn right
    delay(470);
    dist = ultraSensor3.distanceCm();
    if ( dist < 45 )
  {
    dcMotor1_m.run(-200);
    dcMotor2_m.run(-200);
    delay( 1000 );
   
    }
    }
  else
  {
    dcMotor1_m.run(50);
    dcMotor2_m.run(-50); //makes go forward 
    delay(100);
  }
  
  }

  //stop ultra-sensor when starts 180



