#ifndef _PATIENTS_H_
#define _PATIENTS_H_
#include <fstream>
#include "RandomAssign.h"

class Patients
{
	public:
    RandomAssign *temp;
    static int patients_count;
    std::string patient_name;
    int check_in;
    int wait_time;
    int treat_time;
    int priority_number;
    std::vector<std::string> names;

    Patients()
    {
      patient_name = "";
      check_in = -1;
      wait_time = -1;
      treat_time = -1;
      priority_number = -1;
    }

		Patients(int t, int priority)
		{
      nameInput();
      temp = new RandomAssign(temp->next_int(10000000));
      patient_name = names[temp->next_int(names.size())];
			check_in = t;
			wait_time = -1;
			treat_time = -1;
			priority_number = priority;
			patients_count++;
		};

    bool operator<(const Patients& other) const
    {
      return priority_number < other.priority_number;
    }

    void nameInput()
    {
      std::ifstream patients;
      patients.open("patients.txt");
      std::string tempName;
      while (patients.good()) {
        patients >> tempName;
        names.push_back(tempName);
      }
    }


};

int Patients::patients_count = 0;
#endif