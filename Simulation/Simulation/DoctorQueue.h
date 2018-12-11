#pragma once
#include "HospitalQueue.h"
#include "Record.h"

class DoctorQueue : public HospitalQueue
{
public:
  Patients * treating = new Patients;
  HospitalQueue * Doctor;
  int min_treatment_time;
  int max_treatment_time;
  int treatment_time;
  int start_treatment_time = -1;
  int end_treatment_time = -1;
  bool report_output;


  DoctorQueue(RandomAssign *random, HospitalQueue *N,
    int min_treatment_time_, int max_treatment_time_, bool output) :
    HospitalQueue(random), Doctor(N), min_treatment_time(min_treatment_time_),
    max_treatment_time(max_treatment_time_), report_output(output) {}

  void update(int t)
  {
    if (treating->end_treatment_time != -1)
    {
      if (treating->end_treatment_time == t) {
        if (report_output)
        {
          std::cout << "Doctor finished treatment for " << treating->patient_name << " with priority " << treating->priority_number << " at " << t << std::endl;
        }
        Record *pushRecord = new Record;
        pushRecord->update_report(treating);
        treating->end_treatment_time = -1;
      }
      return;
    }



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
          end_treatment_time = t + treatmentTime; // NEW
          p->treat_time = treatment_time;
          p->end_treatment_time = end_treatment_time;
          p->wait_time = start_treatment_time - p->check_in;
          if (report_output)
          {
            std::cout << "Doctor starting treatment for " << p->patient_name << " with priority " << p->priority_number << " at " << t << std::endl;
          }
          *treating = *p;
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
      end_treatment_time = t + treatmentTime; // NEW
      p->treat_time = treatment_time;
      p->end_treatment_time = end_treatment_time;
      p->wait_time = start_treatment_time - p->check_in;
      if (report_output)
      {
        std::cout << "Doctor starting treatment for " << p->patient_name << " with priority " << p->priority_number << " at " << t << std::endl;
      }
      *treating = *p;
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