#pragma once
#include "HospitalQueue.h"

class DoctorQueue : public HospitalQueue
{
public:
  HospitalQueue * Doctor = nullptr;
  int min_treatment_time;
  int max_treatment_time;
  int treatment_time;
  int start_treatment_time;
  bool report_output;


  DoctorQueue(RandomAssign *random, HospitalQueue *N,
    int min_treatment_time_, int max_treatment_time_, bool output) :
    HospitalQueue(random), Doctor(N),
    min_treatment_time(min_treatment_time_), max_treatment_time(max_treatment_time_), report_output(output) {}

  void update(int t)
  {
    if (!highP_patients.empty()) {
      HospitalQueue *Doctor = nullptr;
      if (Doctor->highP_patients.empty()) {
        return;
      }
      Patients *p = nullptr;
      *p = highP_patients.top();
      highP_patients.pop();
      int treatmentTime = max_treatment_time - min_treatment_time;
      treatment_time = min_treatment_time + pushRandom->next_int(treatmentTime);
      start_treatment_time = t;
      if (report_output)
      {
        std::cout << "Starting treatment for " << p->patient_name << " at " << t << std::endl;
      }
    }
    else if (!lowP_patients.empty())
    {
      HospitalQueue *Doctor = nullptr;
      if (Doctor->lowP_patients.empty()) {
        return;
      }
      Patients *p = nullptr;
      *p = lowP_patients.top();
      lowP_patients.pop();
      int treatmentTime = max_treatment_time - min_treatment_time;
      treatment_time = min_treatment_time + pushRandom->next_int(treatmentTime);
      start_treatment_time = t;
      if (report_output)
      {
        std::cout << "Starting treatment for " << p->patient_name << " at " << t << std::endl;
      }
    }
    else if (treatment_time < t - start_treatment_time)
    {
      Patients *p = nullptr;
      *p = lowP_patients.top();
      lowP_patients.pop();
      if (report_output)
      {
        std::cout << "Treatment for " << p->patient_name << " finished at " << t << std::endl;
      }
    }
  }
};