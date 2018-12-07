#pragma once
#include "HospitalQueue.h"
#include "RandomAssign.h"

class NurseQueue : public HospitalQueue
{
public:
  HospitalQueue *Nurse1, *Nurse2;
  int min_service_time;
  int max_service_time;
  int service_time;
  int start_service_time;
  bool report_output;

  // For 2 Nurses
  NurseQueue(RandomAssign *random, HospitalQueue *N1, HospitalQueue *N2,
    int min_service_time_, int max_service_time_, bool output) :
    HospitalQueue(random), Nurse1(N1), Nurse2(N2),
    min_service_time(min_service_time_), max_service_time(max_service_time_), report_output(output) {}
  // For 1 Nurse
  NurseQueue(RandomAssign *random, HospitalQueue *N1,
    int min_service_time_, int max_service_time_, bool output) :
    HospitalQueue(random), Nurse1(N1),
    min_service_time(min_service_time_), max_service_time(max_service_time_), report_output(output) {}

  void update(int t)
  {

  }
};