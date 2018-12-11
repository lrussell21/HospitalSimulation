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
  double p_rate_per_min;
  int influx;
  std::string p_name;
  bool report_output;
  RandomAssign *pushRandom;
  std::set<std::string> names;
public:
  ReceptionQueue(RandomAssign *r, int influx_rate, std::string pname, bool output):
                 HospitalQueue(r), p_influx(influx_rate), p_name(pname), report_output(output)
  {
    p_rate_per_min = influx_rate / 60.0;
    pushRandom = r;
    influx = influx_rate;
    nameInput();
  }

  void update(int t) {
    for (int amountPat = 0; amountPat < influx; amountPat++) {
      if (pushRandom->next_double() < p_rate_per_min) {
        priorityPass = pushRandom->rand_priority();
        Patients *patient = new Patients(t, priorityPass);
        patient->patient_name = setRandomName();
        if (priorityPass <= 10) {
          lowP_patients.push(*patient);
        }
        else {
          highP_patients.push(*patient);
        }
        if (report_output) {
          std::cout << "Patient " << patient->patient_name << " has checked in with a priority of "
            << patient->priority_number
            << " at " << t << std::endl;
        }
      }
    }
  }


  void getPatName() {

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
    pushRandom = new RandomAssign(pushRandom->next_int(10000000));
    std::set<std::string>::iterator it = names.begin();
    int randTemp = pushRandom->next_int(names.size());
    for (int i = 0; i < randTemp; ++i)
    {
      ++it;
    }
    return *it;
  }
};