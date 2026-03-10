#include <Servo.h>

Servo clothServo;

int rainSensorPin = 2;  
int rainStatus = 0;

void setup() {
  clothServo.attach(9);  // Servo connected to pin 9
  pinMode(rainSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  rainStatus = digitalRead(rainSensorPin);

  if (rainStatus == LOW) {  
    // Rain detected
    Serial.println("Rain Detected! Retracting clothes...");
    clothServo.write(0);   // Rotate servo to 0° (inside)
    delay(1000);
  } else {
    // No rain
    Serial.println("No Rain. Extending clothes...");
    clothServo.write(90);  // Rotate servo to 90° (outside)
    delay(1000);
  }
}
