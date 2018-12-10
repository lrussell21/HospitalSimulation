#pragma once
#include <vector>
#include "RecptionQueue.h"
#include "DoctorQueue.h"
#include "NurseQueue.h"
#include "RandomAssign.h"


class Simulator
{
private:
  int runtime;
  std::vector<HospitalQueue *> queues;
  //Report *m_report;
  RandomAssign *random;
  bool report_output;

public:

  Simulator(int doctors,int nurses,int sim_duration, int patient_income_rate, int min_treatment_time, int max_treatment_time, bool report) :
    runtime(sim_duration), report_output(report)
  {
    random = new RandomAssign;
    ReceptionQueue *reception = new ReceptionQueue(random, patient_income_rate, "Reception Queue", report_output);
    queues.push_back(reception);
    if (nurses == 1) {
      NurseQueue *nurse1 = new NurseQueue(random, reception, min_treatment_time, max_treatment_time, report_output);
      queues.push_back(nurse1);
    }
    if (nurses == 2) {
      NurseQueue *nurse1 = new NurseQueue(random, reception, min_treatment_time, max_treatment_time, report_output);
      NurseQueue *nurse2 = new NurseQueue(random, reception, min_treatment_time, max_treatment_time, report_output);
      queues.push_back(nurse1);
      queues.push_back(nurse2);
    }
    if (doctors == 1) {
      DoctorQueue *doc1 = new DoctorQueue(random, reception, min_treatment_time, max_treatment_time, report_output);
      queues.push_back(doc1);
    }
    if (doctors == 2) {
      DoctorQueue *doc1 = new DoctorQueue(random, reception, min_treatment_time, max_treatment_time, report_output);
      DoctorQueue *doc2 = new DoctorQueue(random, reception, min_treatment_time, max_treatment_time, report_output);
      queues.push_back(doc1);
      queues.push_back(doc2);
    }
  }

  void run()
  {
    for (int i = 0; i < runtime; ++i)
    {
      for (unsigned int j = 0; j < queues.size(); ++j)
        queues[j]->update(i);
    }
  }
};