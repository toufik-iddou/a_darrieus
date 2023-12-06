void loop(void) {
  if (values.mode == 2) {
    long unsigned int currentMillis = millis() ;
    float T = 2 * PI / W;
    //currentMillis -= floor((currentMillis) / (T)) * (T);
    float alpha = angle(W * currentMillis/1000, values.TSR);
    Serial.println(alpha);
    int pos = angleToPosition(alpha);
    Serial.println(pos);
     moveToPosition(pos);
    
  }
  server.handleClient();
}
