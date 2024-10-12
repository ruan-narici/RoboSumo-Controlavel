#include <WiFi.h>
#include <Stepper.h>

#define PIN_LEFT_STEPPER_1 25
#define PIN_LEFT_STEPPER_2 26
#define PIN_LEFT_STEPPER_3 27
#define PIN_LEFT_STEPPER_4 14
#define PIN_RIGHT_STEPPER_1 23
#define PIN_RIGHT_STEPPER_2 22
#define PIN_RIGHT_STEPPER_3 21
#define PIN_RIGHT_STEPPER_4 19

#define PIN_LED_DATA_RECEIVED 4
#define PIN_LED_ROBOT_ONLINE 5
#define PIN_LED_ROBOT_CONNECTED 18


const char* ssid = "ROBO-RUAN_NARICI";
const char* pass = "12345678";
const int stepsPerRevolution = 2048; // 2038 = 360 no Motor Step
bool robot_led_status = 0; // Status LED (ONLINE OR CONNECTED)
bool robot_led_data_received = 0; // Alerta para recebimento de dados

Stepper myLeftStepper(stepsPerRevolution, PIN_LEFT_STEPPER_1, PIN_LEFT_STEPPER_3, PIN_LEFT_STEPPER_2, PIN_LEFT_STEPPER_4);
Stepper myRightStepper(stepsPerRevolution, PIN_RIGHT_STEPPER_1, PIN_RIGHT_STEPPER_3, PIN_RIGHT_STEPPER_2, PIN_RIGHT_STEPPER_4);
 
WiFiServer sv(80); //Cria um servidor na porta 80

void run();
void httpListener();

void setup() {
  run();
}

void loop() {
  httpListener();
}