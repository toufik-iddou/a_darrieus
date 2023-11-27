
void setup(void) {
  // GPIO
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  digitalWrite(DIR_PIN, LOW);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  Serial.begin(9600);
  //interruption
  attachInterrupt(digitalPinToInterrupt(ch1), onChangePosition, CHANGE);
  //init EEPROM size
  EEPROM.begin(MEMORY_SIZE);
  // wifi connection
   WiFi.softAP(ssid, password);

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // MDNS
  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  // rootes
  server.on("/",HTTP_GET, handleGetHome);
  server.on("/",HTTP_POST, handlePostHome);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}
