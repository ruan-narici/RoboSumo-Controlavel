void setLedStatusRobot(bool status) {
  robot_led_status = status;
  showLedStatus();
}

void showLedStatus() {
  if (robot_led_status == 0) {
    digitalWrite(PIN_LED_ROBOT_CONNECTED, LOW);
    digitalWrite(PIN_LED_ROBOT_ONLINE, HIGH);
  } else {
    digitalWrite(PIN_LED_ROBOT_CONNECTED, HIGH);
    digitalWrite(PIN_LED_ROBOT_ONLINE, LOW);
  }
}

void setLedDataReceived(bool status) {
  robot_led_data_received = status;
  showDataReceived();
}

void showDataReceived() {
  if (robot_led_data_received == 1) {
    digitalWrite(PIN_LED_DATA_RECEIVED, HIGH);
  } else {
    digitalWrite(PIN_LED_DATA_RECEIVED, LOW);
  }
}