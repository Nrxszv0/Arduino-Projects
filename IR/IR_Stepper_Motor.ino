#include <Stepper.h>
#include <IRremote.h>
int stepsPerRevolution = 2048, stepSpeed = 13, dly = 250;
int N1 = 5, N2 = 4, N3 = 3, N4 = 2;
int stepVal = 256;
String command = "";
int irPin = 6;
Stepper stepMotor(stepsPerRevolution, N1, N3, N2, N4);
IRrecv IR(irPin);
decode_results cmd;
bool stepEnabled = false, stepCW=false, stepCC = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepMotor.setSpeed(stepSpeed);
  IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
//  stepMotor.step(1);
  while(IR.decode(&cmd) == 0) {
    
  }
  delay(dly);
  Serial.print(cmd.value, HEX);
  Serial.print("==");
  IR.resume();
  if (cmd.value == 0xFFA25D || cmd.value == 0xE318261B) {
    command = "pwr";
    stepEnabled = true;    
    Serial.print(command);
    Serial.println(", Stepper Enabled"); 
  }
  if (cmd.value == 0xFFE21D || cmd.value ==0xEE886D7F) {
    command = "stop";   
    stepEnabled = false;    
    Serial.print(command);
    Serial.println(", Stepper Disabled");  
  }
  if ((cmd.value == 0xFFE01F || cmd.value ==0xF076C13B) && stepEnabled) {
    command = "down";  
    stepCW = true;  
    stepCC = false;
    Serial.print(command);
    Serial.println(", Stepper Moving Counter Clockwise");
  }
  if ((cmd.value == 0xFF906F || cmd.value ==0xE5CFBD7F && stepEnabled)) {
    command = "up"; 
    stepCW = false;  
    stepCC = true;
    Serial.print(command);
    Serial.println(", Stepper Moving Counter Clockwise");
  }

  if(stepCW && stepEnabled){
    stepMotor.step(stepVal);    
  }
  if(stepCC && stepEnabled){
    stepMotor.step(-stepVal);
  }
}
