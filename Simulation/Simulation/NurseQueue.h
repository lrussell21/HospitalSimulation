#pragma once
#include "HospitalQueue.h"
#include "RandomAssign.h"

class NurseQueue : public HospitalQueue
{
public:
  HospitalQueue *Nurse;
  int min_treatment_time;
  int max_treatment_time;
  int treatment_time;
  int start_treatment_time;
  bool report_output;


  NurseQueue(RandomAssign *random, HospitalQueue *N,
    int min_treatment_time_, int max_treatment_time_, bool output) :
    HospitalQueue(random), Nurse(N),
    min_treatment_time(min_treatment_time_), max_treatment_time(max_treatment_time_), report_output(output) {}

  void update(int t)
  {
    if (dummy_patients.empty())
    {
      HospitalQueue *Nurse;
      if (Nurse->dummy_patients.empty()) {
        return;
      }
      Patients *p;
      *p = dummy_patients.top();
      dummy_patients.pop();
      int treatmentTime = max_treatment_time - min_treatment_time;
      treatment_time = min_treatment_time + pushRandom->next_int(treatmentTime);
      start_treatment_time = t;
      if (report_output)
      {
        std::cout << "Starting treatment for " << p->patient_name << " at " << t << std::endl;
      }
    }
  }
};