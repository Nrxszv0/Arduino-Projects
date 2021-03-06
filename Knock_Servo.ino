#include <Servo.h>
Servo kServo;
int servoPin = 10, rLED = 11, yLED = 12, gLED = 13, btnPin = 2, btnVal, piezoPin = A0, knockVal, quietKnock = 150, loudKnock = 300, knockNum = 0, minKnockVal = 125, totalGoodKnocks = 3, unlockedSerVal = 0, lockedSerVal = 90, dly = 1000, yLEDdly = 50;
boolean isLocked = false;
String unlockedMsg = "The box is unlocked", lockedMsg = "The box is locked", knocksLeftMsg = " more knocks left", goodKnockMsg = "Good knock value: ", badKnockMsg = "Bad knock value: ";
void setup() {
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(btnPin, INPUT);
  digitalWrite(gLED, HIGH);
  kServo.attach(servoPin);
  kServo.write(unlockedSerVal);
  Serial.println(unlockedMsg);
}

void loop() {
  if (isLocked == false) {
    btnVal = digitalRead(btnPin);
    if (btnVal == HIGH) {
      isLocked = true;
      digitalWrite(gLED, LOW);
      digitalWrite(rLED, HIGH);
      kServo.write(lockedSerVal);
      Serial.println(lockedMsg);
      delay(dly); //change to var

    }
  }
  if (isLocked == true) {
    knockVal = analogRead(piezoPin);
    if (knockNum < totalGoodKnocks && knockVal > minKnockVal) {
      if (checkForKnock(knockVal) == true) {
        knockNum++;
      }
      Serial.print(totalGoodKnocks - knockNum);
      Serial.println(knocksLeftMsg);
    }
    if (knockNum >= totalGoodKnocks) {
      isLocked = false;
      kServo.write(unlockedSerVal);
      digitalWrite(gLED, HIGH);
      digitalWrite(rLED, LOW);
      Serial.println(unlockedMsg);
      knockNum = 0;
    }
  }
}
boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) {
    digitalWrite(yLED, HIGH);
    delay(yLEDdly); // change to var
    digitalWrite(yLED, LOW);
    Serial.print(goodKnockMsg);
    Serial.println(value);
    return true;
  }
  else {
    Serial.print(badKnockMsg);
    Serial.println(value);
    return false;
  }
}

