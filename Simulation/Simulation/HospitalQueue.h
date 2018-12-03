#pragma once
#include <queue>
#include "Patients.h"
#include "RandomAssign.h"

class HospitalQueue
{
public:
  std::queue<Patients*> dummy_patients;
  RandomAssign *pushRandom;
  virtual void update(int t) = 0;
  HospitalQueue(RandomAssign *RandomAssign)
  {
    pushRandom = RandomAssign;
  }

};