#ifndef _PATIENTS_H_
#define _PATIENTS_H_

class Patients
{
	public:
		Patients(int t, int priority)
		{
			 patient_id = -1;
			 check_in = t;
			 wait_time = -1;
			 treat_time = -1;
			 priority_number = priority;
			 patients_count++;
		};
		static int patients_count = 0;
		int patient_id;
		int check_in;
		int wait_time;
		int treat_time;
		int priority_number;

};
#endif