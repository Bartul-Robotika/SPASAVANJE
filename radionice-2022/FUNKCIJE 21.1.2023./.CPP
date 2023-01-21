void RobotLine::desnizid(){
  armOpen();
  if (rightFront() < leftFront()) {
  if (rightFront() < 120) {
    go(40, 60);
  }
  else {
    go(60, 40);
    }
  }
}

void RobotLine::lijevizid(){
  armOpen();
  if (leftFront() < rightFront()) {
  if (leftFront() < 120) {
    go(60, 40);
  }
  else {
    go(40, 60);
    }
  }
}

void RobotLine::labirint(){
static int brojac = 0;
char simbol[10 + sizeof(char)];
  armOpen();
  if(rightFront() < 130 and front(3) < 140 and front(3) > 80) {
    go(-90, 90);
    delayMs(500);
    brojac++;
  }
  if(leftFront() < 130 and front(3) < 140 and front(3) > 80) {
    go(90, -90);
    delayMs(500);
    brojac++;
  }
  if(brojac == 2 and front() < 140) {
    go(90, -90);
    brojac++;
  }
  if(brojac == 6 and front() < 140) {
    go(-90, 90);
    brojac++;
  }
  if(rightFront() > 200 and leftFront() > 200) {
    go(90, 90);
  }
  if(line(0) and line(8)) {
    stop();
    end();
  }
  sprintf(simbol, "%d", brojac);
  display(simbol);
}
