#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "HospitalQueue.h"

class ReceptionQueue : public HospitalQueue
{
private:
  int priorityPass;
  int p_influx;
  int patCounter = 0;
  std::string p_name;
  bool report_output;
  RandomAssign *pushRandom = new RandomAssign;
  std::set<std::string> names;
public:
  ReceptionQueue(RandomAssign *r, int influx_rate, std::string pname, bool output):
                 HospitalQueue(r), p_influx(influx_rate), p_name(pname), report_output(output)
  {
    pushRandom = r;
    nameInput();
  }

  void update(int t)
  {
    if (t % 60 == 0)
    {
      patCounter = p_influx;
    }
    if(patCounter != 0)
    {
      priorityPass = pushRandom->rand_priority();
      Patients *patient = new Patients(t, priorityPass);
      patient->patient_name = setRandomName();
      if (priorityPass <= 10) {
        lowP_patients.push(*patient);
      }
      else
      {
        highP_patients.push(*patient);
      }
      if (report_output)
      {
        std::cout << "Patient " << patient->patient_name << " has checked in with a priority of "
          << patient->priority_number
          << " at " << t << std::endl;
      }
      patCounter--;
    }
  }

  void nameInput()
  {
    std::ifstream patients;
    patients.open("patients.txt");
    std::string tempName;
    while (patients.good()) {
      patients >> tempName;
      names.insert(tempName);
    }
  }

  std::string setRandomName() {
    std::set<std::string>::iterator it = names.begin();
    int randTemp = pushRandom->randIntRange(names.size());
    for (int i = 0; i < randTemp; ++i)
    {
      ++it;
    }
    return *it;
  }
};