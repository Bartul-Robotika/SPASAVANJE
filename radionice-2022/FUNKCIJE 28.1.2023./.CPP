void RobotLine::desnizid() {
  armOpen();
  if (rightFront() < leftFront()) {
    if (rightFront() < 120) {
      go(45, 55);
    }
    else {
      go(55, 45);
    }
  }
}

void RobotLine::lijevizid() {
  armOpen();
  if (leftFront() < rightFront()) {
    if (leftFront() < 120) {
      go(55, 45);
    }
    else {
      go(45, 55);
    }
  }
}

void RobotLine::labirint() {
  static int brojac = 0;
  char simbol[10 + sizeof(char)];
  armOpen();
  if (rightFront() < 130 and front(3) < 140 and front(3) > 80) {
    go(-90, 90);
    delayMs(500);
    brojac++;
  }
  if (leftFront() < 130 and front(3) < 140 and front(3) > 80) {
    go(90, -90);
    delayMs(500);
    brojac++;
  }
  if (brojac == 2 and front() < 140) {
    go(90, -90);
    brojac++;
  }
  if (brojac == 6 and front() < 140) {
    go(-90, 90);
    brojac++;
  }
  if (rightFront() > 200 and leftFront() > 200) {
    go(127, 127);
  }
  if (line(0) and line(8)) {
    stop();
    end();
  }
  sprintf(simbol, "%d", brojac);
  display(simbol);
}

void RobotLine::sporopratiliniju() {
  if (lineAny()) {
    lineFollow();
  }
  if (!lineAny()) {
    go(50, 50);
  }
  if (line(8) and line(0)) {
    go(50, 50);
  }
  if (pitch() < -10) {
    go(50, 50);
  }
}

void RobotLine::brzopratiliniju() {
  if (line(8))
    go(-90, 90);
  else if (line(0))
    go(90, -90);
  else if (line(7))
    go(10, 90);
  else if (line(1))
    go(90, 10);
  else if (line(6))
    go(40, 70);
  else if (line(2))
    go(70, 40);
  else if (line(5))
    go(30, 60);
  else if (line(3))
    go(60, 30);
  else if (line(4))
    go(90, 90);
  else
    go(90, 90);

  if (line(8) and line(0)) {
    go(90, 90);
  }
  if (pitch() < -10) {
    go(90, 90);
  }
}

void RobotLine::izbjegavanjejobjekta() {
  if (lineAny()) {
    lineFollow();
  }
  if (front(5) < 140 and front(5) > 80) {
    go(90, -90);
    delayMs(500);
    while (!lineAny()) {
      go(20, 80);
      noLoopWithoutThis();
    }
    go(90, 0);
    delayMs(500);
    go(50, 50);
    delayMs(500);
  }
}
