void leftMotorGoToFront() {
  myLeftStepper.step(stepsPerRevolution);
}

void leftMotorGoToBack() {
  myLeftStepper.step(-stepsPerRevolution);
}

void rightMotorGoToFront() {
  myRightStepper.step(stepsPerRevolution);
}

void rightMotorGoToBack() {
  myRightStepper.step(-stepsPerRevolution);
}