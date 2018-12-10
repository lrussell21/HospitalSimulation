#pragma once
#include <iostream>
#include "Patients.h"

class Record
{
public:
  Record(){}

  void update_report(Patients *Patient)
  {
    total_wait_time += Patient->wait_time;
    total_treatment_time += Patient->treat_time;
    total_num_patients += 1;
  };

  void print_report()
  {
    std::cout << "Total Patients Treated: " << total_num_patients << std::endl;
    std::cout << "Average treatment time: " << (double)total_treatment_time / total_num_patients << std::endl;
    std::cout << "Average wait time: " << (double)total_wait_time / total_num_patients << std::endl;
  };

private:
  static int total_treatment_time;
  static int total_wait_time;
  static int total_num_patients;
  Patients *test = new Patients;
};

int Record::total_treatment_time = 0;
int Record::total_wait_time = 0;
int Record::total_num_patients = 0;