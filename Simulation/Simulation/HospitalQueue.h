#pragma once
#include <queue>
#include "Patients.h"
#include "RandomAssign.h"

class HospitalQueue
{
public:
  std::priority_queue<Patients> lowP_patients;
  std::priority_queue<Patients> highP_patients;
  std::vector<Patients> treatedPatients;
  RandomAssign *pushRandom;
  virtual void update(int t) = 0;
  HospitalQueue(RandomAssign *RandomAssign)
  {
    pushRandom = RandomAssign;
  }
  void patSearch(std::string name)
  {
    for (int pat = 0; pat < treatedPatients.size(); ++pat)
    {
      if (treatedPatients[pat].patient_name == name) {
        std::cout << name << " check in with a priority of " << treatedPatients[pat].priority_number
          << ", had a wait time of " << treatedPatients[pat].wait_time << ", and a treatment time of "
          << treatedPatients[pat].treat_time << "." << std::endl;
      }
    }
  }
};