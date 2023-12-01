
void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/html", navigateTo(""));
  digitalWrite(led, 0);
}

void handleGetHome() {
  digitalWrite(led, 1);
  server.send(200, "text/html", homePage());
  digitalWrite(led, 0);
}

void handlePostHome() {
  digitalWrite(led, 1);
  writeDataToEEPROM(server.arg("mode").toFloat(),server.arg("V").toFloat(), server.arg("R").toFloat(), server.arg("TSR").toFloat(), server.arg("theta").toFloat());

  server.send(200, "text/html", navigateTo(""));

  digitalWrite(led, 0);
  switch (server.arg("mode").toInt()) {
    case 0 : //alpha
      moveToPosition(angleToSteps(server.arg("alpha").toFloat()));
      Serial.println(angleToSteps(server.arg("alpha").toFloat()));
      break;
    case 1: //theta
      moveToPosition(angleToSteps(server.arg("theta").toFloat()));
      Serial.println(angleToSteps(server.arg("theta").toFloat()));
      break;
    case 2: //movement
      Serial.println(2);
      break;
  }
}

void handleNotFound() {
  digitalWrite(led, 1);
  server.send(404, "text/plain", "redirect to auther page");
  digitalWrite(led, 0);
}
void handleNotFound2() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}
