void IRAM_ATTR onChangePosition() {
  if(digitalRead(ch1) == digitalRead(ch2) ){
    counter++;
    }else{
      counter--;
      }
     counter%=400; 
}
float angle(float theta,float TSR){
  float alpha = atan(sin(theta)/(cos(theta)+TSR))/DEG2RAD;
  return alpha ;
  }
  
 int angleToSteps(float angle){
  return (int)(angle/1.8);
  }

void moveToPosition(int pos){
 int steps = pos-counter/2;
  if(steps==0){
   return;
   }
  float microTimeStep = timeStep*500000;
  if(steps>0){
    digitalWrite(DIR_PIN,HIGH);
    }
  else{ 
    digitalWrite(DIR_PIN,LOW);
    steps*=(-1);
    }
  for(int i =0;i<steps;i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(microTimeStep);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(microTimeStep);
    }
  }
