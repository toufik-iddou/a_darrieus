void loop(void) {
  if (values.mode == 2) {
    long unsigned int currentMillis = millis();
    float T = 2 * PI / W;
    currentMillis -= floor((currentMillis) / (T)) * (T);
    float alpha = angle(W * currentMillis, values.TSR);
    unsigned char pos = angleToPosition(alpha);
    if (!moveToPosition(pos)) {
      server.handleClient();
    }
  } else {
    server.handleClient();
    delay(2);
  }
}
