//types
typedef struct {
  char mode;
  float V;
  float R;
  float TSR;
  float theta;
 }MyValues;

//Model variables
MyValues values;
//system variables
float W;
bool FixedMode = false;
const char *ssid = "hemiche";
const char *password = "12345678";
WebServer server(80);
const int led = 13;
int counter=0;
ESP32Timer ITimer1(1);
//functions
//root functions
void handleRoot();
void handleNotFound(); 
void handleNotFound2(); 
String navigateTo(String path);
String homePage();
void handleGetHome();
void handlePostHome();
//memory functions
void writeDataToEEPROM(float V,float R,float TSR,float theta);
MyValues readDataFromEEPROM();
//timers functions
void IRAM_ATTR onChangePosition();
bool IRAM_ATTR movementInterruption(void * timerNo);
// bool IRAM_ATTR TimerHandler1(void * timerNo)
//model functions
float angle(float theta,float TSR);
unsigned char angleToPosition(float angle);
bool moveToPosition(unsigned char pos);
void dispatch();

