#pragma once
#include "HospitalQueue.h"

class DoctorQueue : public HospitalQueue
{
public:
  HospitalQueue * Doctor;
  int min_treatment_time;
  int max_treatment_time;
  int treatment_time;
  int start_treatment_time;
  bool report_output;


  DoctorQueue(RandomAssign *random, HospitalQueue *N,
    int min_treatment_time_, int max_treatment_time_, bool output) :
    HospitalQueue(random), Doctor(N), min_treatment_time(min_treatment_time_),
    max_treatment_time(max_treatment_time_), report_output(output) {}

  void update(int t)
  {
    if (highP_patients.empty())
    {
      HospitalQueue *Doctor1;
      if (Doctor->highP_patients.empty())
      {
        if (lowP_patients.empty())
        {
          HospitalQueue *Doctor2;
          if (Doctor->lowP_patients.empty())
          {
            return;
          }
          Doctor2 = Doctor;
          Patients *p = new Patients;
          *p = Doctor2->lowP_patients.top();
          Doctor2->lowP_patients.pop();
          int treatmentTime = max_treatment_time - min_treatment_time;
          treatment_time = min_treatment_time + pushRandom->next_int(treatmentTime);
          start_treatment_time = t;
          if (report_output)
          {
            std::cout << "Starting treatment for " << p->patient_name << " with priority " << p->priority_number << " at " << t << std::endl;
          }
        }
        return;
      }
      Doctor1 = Doctor;
      Patients *p = new Patients;
      *p = Doctor1->highP_patients.top();
      Doctor1->highP_patients.pop();
      int treatmentTime = max_treatment_time - min_treatment_time;
      treatment_time = min_treatment_time + pushRandom->next_int(treatmentTime);
      start_treatment_time = t;
      if (report_output)
      {
        std::cout << "Starting treatment for " << p->patient_name << " with priority " << p->priority_number << " at " << t << std::endl;
      }
    }
    else if (treatment_time < t - start_treatment_time)
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