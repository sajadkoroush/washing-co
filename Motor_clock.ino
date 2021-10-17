/***************************
*                          *
*Created By : SajadKoroush *
*                          *
****************************/


#include <Wire.h>
#include "ds3231.h" 

struct ts timestamp;

int Motor = 9;
int Button_timestamp = 6;
int Button_timestamp_2 = 7;
int Test_Motor = 4;
 
int state = 0;
int state_2 = 0;
int Test_state = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_INTCN);
  pinMode(Motor, OUTPUT);
  pinMode(Button_timestamp, INPUT);
  pinMode(Button_timestamp_2, OUTPUT);
  pinMode(Test_Motor , INPUT);
}

void loop() {
  state == digitalRead(Button_timestamp);
  state_2 == digitalRead(Button_timestamp_2);
  Test_state = digitalRead(Test_Motor);
  DS3231_get(&timestamp);
  delay(500);
  if (timestamp.hour == 9  & timestamp.min == 0 & timestamp.sec == 0 )
  {
    digitalWrite(Motor, HIGH);
    delay(15000);
  }
  if (state == HIGH)
  {
    timestamp.hour = 12;
    timestamp.sec = 0; 
    timestamp.min = 0;
  }
  if (state_2 == HIGH)
  {
    timestamp.hour = 6;
    timestamp.sec = 0;
    timestamp.min = 0;
  }
  if (Test_state == HIGH)
  {
    digitalWrite(Motor, HIGH);
    Serial.println("motor");
  }
  else{
    digitalWrite(Motor,LOW);
  }

    Serial.print("Time:");
    String timestr = String(timestamp.hour) + ":" + String(timestamp.min) + ":" + String(timestamp.sec);
    Serial.println(timestr);
    delay(1000);

}
