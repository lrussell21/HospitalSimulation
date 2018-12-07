#pragma once
#include <queue>
#include "Patients.h"
#include "RandomAssign.h"

class HospitalQueue
{
public:
  std::priority_queue<Patients> lowP_patients;
  std::priority_queue<Patients> highP_patients;
  RandomAssign *pushRandom;
  virtual void update(int t) = 0;
  HospitalQueue(RandomAssign *RandomAssign)
  {
    pushRandom = RandomAssign;
  }
};