#ifndef _PATIENTS_H_
#define _PATIENTS_H_

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
    int end_treatment_time;
    std::set<std::string> names;

    Patients()
    {
      patient_name = "";
      check_in = -1;
      wait_time = -1;
      treat_time = -1;
      priority_number = -1;
      end_treatment_time = -1;
    }

		Patients(int t, int priority)
		{
      patient_name = "UNSET";
			check_in = t;
      wait_time = 0;
			treat_time = 0;
			priority_number = priority;
			patients_count++;
		};

    bool operator<(const Patients& other) const
    {
      return priority_number < other.priority_number;
    }

    /*
    void nameInput()
    {
      std::ifstream patients;
      patients.open("patients.txt");
      std::string tempName;
      while (patients.good()) {
        patients >> tempName;
        names.insert(tempName);
      }
    }

    void setRandomName() {
      temp = new RandomAssign(temp->next_int(10000000));
      std::set<std::string>::iterator it = names.begin();
      int randTemp = temp->next_int(names.size());
      for (int i = 0; i < randTemp; ++i)
      {
        ++it;
      }
      patient_name = *it;
    }
    */
};

int Patients::patients_count = 0;
#endif