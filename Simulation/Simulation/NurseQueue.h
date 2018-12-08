#pragma once
#include "HospitalQueue.h"

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
    if (lowP_patients.empty())
    {
      HospitalQueue *Nurse1;
      if (Nurse->lowP_patients.empty()) {
        return;
      }
      Nurse1 = Nurse;
      Patients *p = new Patients;
      *p = Nurse1->lowP_patients.top();
      Nurse1->lowP_patients.pop();
      int treatmentTime = max_treatment_time - min_treatment_time;
      treatment_time = min_treatment_time + pushRandom->next_int(treatmentTime);
      start_treatment_time = t;
      if (report_output)
      {
        std::cout << "Nurse starting treatment for " << p->patient_name << " with priority " << p->priority_number << " at " << t << std::endl;
      }
    }
    else if (t - start_treatment_time > treatment_time)
    {
      Patients *p = new Patients;
      *p = lowP_patients.top();
      lowP_patients.pop();
      if (report_output)
      {
        std::cout << "Treatment for " << p->patient_name << " finished at " << t << std::endl;
      }
    }
  }
};