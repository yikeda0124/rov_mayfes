#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLVZcF8_Ys"
#define BLYNK_DEVICE_NAME "esp32"
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include "config.h"

Servo servo1;
const int maxUs = 1900;
const int minUs = 1100;
const int servo1Pin = 25;
const int servo2Pin = 18;
const int servo3Pin = 23;

int value_servo1 = 1900;
int value_servo2 = 1900;
int value_servo3 = 1900;


void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLINK_API_KEY, WIFI_SSID, WIFI_PASSWORD);
  servo1.attach(servo1Pin, minUs, maxUs);
  servo2.attach(servo2Pin, minUs, maxUs);
  servo3.attach(servo2Pin, minUs, maxUs);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1){
  int is_power_on = param[0].asInt();
  if (is_power_on){
      servo1.writeMicroseconds(value_servo1);
      servo2.writeMicroseconds(value_servo2);
      servo3.writeMicroseconds(value_servo3);
  }else{
      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
      servo3.writeMicroseconds(1500);
  }
}

BLYNK_WRITE(V5){
  double value = param[0].asDouble();
  value_servo1 = (value/255.0-0.5)*800+1500;
}

BLYNK_WRITE(V6){
  double value = param[0].asDouble();
  value_servo2 = (value/255.0-0.5)*800+1500;
}

BLYNK_WRITE(V7){
  double value = param[0].asDouble();
  value_servo3 = (value/255.0-0.5)*800+1500;
}

