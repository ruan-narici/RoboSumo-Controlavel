const int stepsPerInterval = 1;

void goToFront() {
  int stepsRemaining1 = stepsPerRevolution / 3; 
  int stepsRemaining2 = stepsPerRevolution / 3;

  while (stepsRemaining1 > 0 || stepsRemaining2 > 0) {
    if (stepsRemaining1 > 0) {
      myLeftStepper.step(stepsPerInterval);
      stepsRemaining1 -= stepsPerInterval;
    }
    if (stepsRemaining2 > 0) {
      myRightStepper.step(stepsPerInterval);
      stepsRemaining2 -= stepsPerInterval;
    }
  }
}

void goToBack() {
  int stepsRemaining1 = stepsPerRevolution / 3; 
  int stepsRemaining2 = stepsPerRevolution / 3;

  while (stepsRemaining1 > 0 || stepsRemaining2 > 0) {
    if (stepsRemaining1 > 0) {
      myLeftStepper.step(-stepsPerInterval);
      stepsRemaining1 -= stepsPerInterval;
    }
    if (stepsRemaining2 > 0) {
      myRightStepper.step(-stepsPerInterval);
      stepsRemaining2 -= stepsPerInterval;
    }
  }
}

void goToLeft() {
  int stepsRemaining1 = stepsPerRevolution / 3; 
  int stepsRemaining2 = stepsPerRevolution / 3;

  while (stepsRemaining1 > 0 || stepsRemaining2 > 0) {
    if (stepsRemaining1 > 0) {
      myLeftStepper.step(-stepsPerInterval);
      stepsRemaining1 -= stepsPerInterval;
    }
    if (stepsRemaining2 > 0) {
      myRightStepper.step(stepsPerInterval);
      stepsRemaining2 -= stepsPerInterval;
    }
  }
}

void goToRight() {
  int stepsRemaining1 = stepsPerRevolution / 3; 
  int stepsRemaining2 = stepsPerRevolution / 3;

  while (stepsRemaining1 > 0 || stepsRemaining2 > 0) {
    if (stepsRemaining1 > 0) {
      myLeftStepper.step(stepsPerInterval);
      stepsRemaining1 -= stepsPerInterval;
    }
    if (stepsRemaining2 > 0) {
      myRightStepper.step(-stepsPerInterval);
      stepsRemaining2 -= stepsPerInterval;
    }
  }
}