#include <iostream>
#include "Patients.h"
#include "RecptionQueue.h"
#include "RandomAssign.h"


int main() {
  RandomAssign* testRandom;
  testRandom = new RandomAssign();
  Patients test1(15, 15);
  Patients test2(20, 7);
  Patients test3(25, 20);
  Patients test4(30, 1);
  Patients test5(35, 17);
  ReceptionQueue testReception(testRandom, 60, "Reception Queue", 1);
  
  for (int i = 0; i < 20; i++) {
    testReception.update(10);
  }
  
  return 0;
}