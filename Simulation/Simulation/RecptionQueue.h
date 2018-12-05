#pragma once
#include <iostream>
#include <string>
#include "HospitalQueue.h"

class ReceptionQueue : public HospitalQueue
{
private:
  int priorityPass;
  int p_influx;
  double p_rate_per_min;
  std::string p_name;
  bool p_report_output;
  RandomAssign *pushRandom;
public:
  ReceptionQueue(RandomAssign *r, int influx_rate, std::string pname, bool output):
                 HospitalQueue(r), p_influx(influx_rate), p_name(pname), p_report_output(output)
  {
    p_rate_per_min = influx_rate / 60.0;
    pushRandom = r;

  }

  void update(int t) {
    if (pushRandom->next_double() < p_rate_per_min) {
      priorityPass = pushRandom->rand_priority();
      Patients *patient = new Patients(t, priorityPass);
      dummy_patients.push(*patient);
      if (p_report_output) {
        std::cout << "Patient " << patient->patient_name << " has checked in with a priority of "
                                << patient->priority_number
                                << " at " << t << std::endl;
      }
    }
  }


};