#include <iostream>
#include "Patients.h"
#include "RecptionQueue.h"
#include "RandomAssign.h"
#include "NurseQueue.h"
//#include "DoctorQueue.h"


// TODO: May need to split priority queue into two so Nurse can just take top of one then doctor can access both.

int main() {

  RandomAssign* testRandom;
  testRandom = new RandomAssign;
  HospitalQueue* testHp;
  Patients test1(15, 15);
  Patients test2(20, 7);
  Patients test3(25, 20);
  Patients test4(30, 1);
  Patients test5(35, 17);
  ReceptionQueue *testReception = new ReceptionQueue(testRandom, 60, "Reception Queue", 0);
  
  for (int i = 0; i < 200; i++) {
    testReception->update(i);
    //std::cout << testRandom->rand_priority() << std::endl;
  }
  testHp = new NurseQueue(testRandom, testReception, 1, 10, true);
  //testHp = new DoctorQueue(testRandom, testReception, 1, 10, true);
  for (int i = 0; i < 200; i++) {
    testHp->update(i);
    //std::cout << testRandom->rand_priority() << std::endl;
  }
  return 0;
}