#pragma once
#include <vector>
#include "HospitalQueue.h"
#include "Record.h"

class NurseQueue : public HospitalQueue
{
public:
  Patients * treating = new Patients;
  HospitalQueue *Nurse;
  int min_treatment_time;
  int max_treatment_time;
  int treatment_time;
  int start_treatment_time = -1;
  int end_treatment_time = -1;
  bool report_output;

  NurseQueue(RandomAssign *random, HospitalQueue *N,
    int min_treatment_time_, int max_treatment_time_, bool output) :
    HospitalQueue(random), Nurse(N),
    min_treatment_time(min_treatment_time_), max_treatment_time(max_treatment_time_), report_output(output) {}

  void update(int t)
  {
    if (treating->end_treatment_time != -1)
    {
      if (treating->end_treatment_time == t) {
        if (report_output)
        {
          std::cout << "Nurse finished treatment for " << treating->patient_name << " with priority " << treating->priority_number << " at " << t << std::endl;
        }
        Record *pushRecord = new Record;
        pushRecord->update_report(treating);
        treating->end_treatment_time = -1;
      }
      return;
    }

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
      end_treatment_time = t + treatmentTime; // NEW
      p->treat_time = treatment_time;
      p->end_treatment_time = end_treatment_time;
      p->wait_time = start_treatment_time - p->check_in;

      //std::cout << "Treatement TIME : " << p->treat_time << std::endl;
      if (report_output)
      {
        std::cout << "Nurse starting treatment for " << p->patient_name << " with priority " << p->priority_number << " at " << t << std::endl;
      }
      *treating = *p;
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