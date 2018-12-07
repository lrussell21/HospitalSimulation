#ifndef _PATIENTS_H_
#define _PATIENTS_H_

class Patients
{
	public:
		Patients(int t, int priority)
		{
       patient_name = -1;
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

  

		static int patients_count;
		int patient_name;
		int check_in;
		int wait_time;
		int treat_time;
		int priority_number;

};

int Patients::patients_count = 0;
#endif