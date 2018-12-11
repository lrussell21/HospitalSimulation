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
    bool output = false;
    for (int pat = 0; pat < treatedPatients.size(); ++pat)
    {
      if (treatedPatients[pat].patient_name == name) {
        output = true;
        std::cout << name << " checked in at " << treatedPatients[pat].check_in << " with a priority of " << treatedPatients[pat].priority_number
          << ", had a wait time of " << treatedPatients[pat].wait_time << " minutes, and a treatment time of "
          << treatedPatients[pat].treat_time << " minutes." << std::endl;
      }
    }
    if (!output)
    {
      std::cout << "No record of " << name << "." << std::endl;
    }
  }
  
  void listAll()
  {
    for (int pat = 0; pat < treatedPatients.size(); ++pat)
    {
      std::cout << treatedPatients[pat].patient_name << std::endl;
    }
  }
};