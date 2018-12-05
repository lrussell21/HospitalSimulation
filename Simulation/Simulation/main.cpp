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
  if (test2 < test1) {
    std::cout << "Yeah Boi" << std::endl;
  }
  ReceptionQueue testReception(testRandom, 60, "Reception Queue", 1);
  
  testReception.update(10);
  testReception.update(20);
  testReception.update(30);
  testReception.update(40);
  testReception.update(50);

  
  return 0;
}