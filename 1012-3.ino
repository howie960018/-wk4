#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 1024;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  pinMode(26, INPUT);
  pinMode(25, INPUT);
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
}

void loop() {
  
   if(digitalRead(26) == HIGH){
      myStepper.step(stepsPerRevolution);
  }
  
  else if(digitalRead(25) == HIGH){
      myStepper.step(-stepsPerRevolution);
    }

}
