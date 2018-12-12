#ifndef _PATIENTS_H_
#define _PATIENTS_H_

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
      patient_name = "";
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
};

int Patients::patients_count = 0;
#endif