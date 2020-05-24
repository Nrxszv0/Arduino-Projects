#include <Servo.h>
Servo kServo;
int servoPin = 10, rLED = 11, yLED = 12, gLED = 13, btnPin = 2, btnVal, piezoPin = A0, knockVal, quietKnock = 10, loudKnock = 100, knockNum = 0;
boolean isLocked = false;
String unlockedMsg = "The box is unlocked", lockedMsg = "The box is locked";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(btnPin, INPUT);
  digitalWrite(gLED, HIGH);
  kServo.attach(10);
  kServo.write(0);
  Serial.println(unlockedMsg);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isLocked == false) {
    btnVal = digitalRead(btnPin);
    if (btnVal == HIGH) {
      isLocked = true;
      digitalWrite(gLED, LOW);
      digitalWrite(rLED, HIGH);
      kServo.write(90); //change to var
      Serial.println(lockedMsg);
      delay(1000); //change to var

    }
  }
  if (isLocked == true) {
    knockVal = analogRead(piezoPin);
    if (knockNum < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) {
        knockNum++;
      }
      Serial.print(3 - knockNum); // change 3 to var
      Serial.println("more knocks left"); //change to var
    }
    if(knockNum >=3) {
      isLocked=false;
      kServo.write(0); // change to var
      digitalWrite(gLED, HIGH);
      digitalWrite(rLED, LOW);
      Serial.println(unlockedMsg);
      knockNum=0;
    }
  }
}
boolean checkForKnock(int value){
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yLED, HIGH);    
    delay(50); // change to var
    digitalWrite(yLED, LOW);
    Serial.print("Good knock value: "); // change to var
    Serial.println(value);    
    return true;
  }
  else {
    Serial.print("Bad knock value: ");
    Serial.println(value);
    return false;
  }
}

