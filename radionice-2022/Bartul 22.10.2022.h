#pragma once
#include "helper.h"
void RobotLine::radionica() {
  static int broj = 0;
  char simbol[10 + sizeof(char)];

  // ZADATAK: napravite if naredbu da se robot zaustavi nakon što se vrati na početak
  if (setup()) {
    armOpen();
  }
    if (broj == 2) {
    go(50, -50);
    delayMs(500);
    go(50, 50);
    delayMs(500);
    go(-50, -50);
    delayMs(500);
    go(50, -50);
    delayMs(500);
    broj++;
  }
  
  if (front() < 120) {
    go(90, -90);
    delayMs(500);
    broj++;
  }
  if (rightFront() < leftFront()){
    if (rightFront() > 120)
      go(80, 20);
    else
      go(20, 80);}
  else if (rightFront() > leftFront()){
    if (leftFront() > 120)
      go(20, 80);
    else
      go(80, 20);
  }
 else
 go(50, 50);


  sprintf(simbol, "%d", broj);
  display(simbol);


}
// ZADATAK: Dodajte praćenje lijevog zida uz postojeće pračenje desnog zida.
// HINT: Koristite grananje if uvjeta

