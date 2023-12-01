// bool IRAM_ATTR TimerHandler1(void * timerNo)
// {
// 	static bool toggle1 = false;

// 	//timer interrupt toggles outputPin
// 	digitalWrite(PIN_D3, toggle1);
// 	toggle1 = !toggle1;

// 	return true;
// }

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

  Serila.print("pos:");
  Serila.println(pos);

  Serila.print("counter:");
  Serila.println(counter);

  Serila.print("steps:");
  Serila.println(steps);
  
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
