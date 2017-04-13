#include "scheduler.h"

/* Pre:		2D Patient array, Doctor array, int, 3D
 *			Patient Array
 * Post:	none
 * Purpose: gets day and time to check if patient can be
 *			added to the correct doctor, and does so
 *********************************************************/
void addAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor,
                    Patient ***&scheduler)
{
	int doctorIndex = -1;
	int dayIndex, timeIndex, patientIndex;
	string doctorName, patientId, time, day;

	cout << "Enter Doctor Name: ";
	getline(cin, doctorName);

	cout << "Enter Patient ID: ";
	getline(cin, patientId);

	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (doctors[i].getName() == doctorName)
		{
			doctorIndex = i;
		}
	}

	for (int w = 0; w < doctors[doctorIndex].getNumberOfPatient; w++)
	{
		if (patients[doctorIndex][w].getId() == patientId)
		{
			patientIndex = w;
		}
	}


	if (patients[doctorIndex][patientIndex].getDoctorId() == doctors[doctorIndex].getId())
	{
		cout << "Enter Time: ";
		getline(cin, time);

		cout << "Enter Day: ";
		getline(cin, day);

		timeIndex = convertTimeToInt(time);
		dayIndex = convertDayToInt(day);

		if (scheduler[doctorIndex][dayIndex][timeIndex].getId() == "")
		{
			scheduler[doctorIndex][dayIndex][timeIndex] = patients[doctorIndex][patientIndex];
		}
		else
		{
			cout << endl << "TIME NOT AVAILABLE" << endl;
		}
	}

}

/* Pre:		2D Patient array, Doctor array, int, 3D
 *			Patient Array
 * Post:	none
 * Purpose: gets original appointment, new appointment,
 *			checks to see if the patient belongs to the
 *			doctor, and changes the appointment
 *********************************************************/
void changeAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor,
	Patient ***&scheduler)
{
	int doctorIndex = -1;
	int dayIndex, timeIndex, newDayIndex, newTimeIndex, patientIndex;
	string doctorName, patientId, time, day;

	cout << "Enter Doctor Name: ";
	getline(cin, doctorName);

	cout << "Enter Patient ID: ";
	getline(cin, patientId);

	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (doctors[i].getName() == doctorName)
		{
			doctorIndex = i;
		}
	}

	for (int w = 0; w < doctors[doctorIndex].getNumberOfPatient; w++)
	{
		if (patients[doctorIndex][w].getId() == patientId)
		{
			patientIndex = w;
		}
	}

	if (patients[doctorIndex][patientIndex].getDoctorId() == doctors[doctorIndex].getId())
	{
		cout << "Enter Original Time: ";
		getline(cin, time);

		cout << "Enter Original Day: ";
		getline(cin, day);
		
		timeIndex = convertTimeToInt(time);
		dayIndex = convertDayToInt(day);
		
		cout << "Enter New Day: ";
		getline(cin, time);

		cout << "Enter New Time: ";
		getline(cin, time);
		
		 newTimeIndex = convertTimeToInt(time);
		 newDayIndex = convertDayToInt(day);

		if (scheduler[doctorIndex][newDayIndex][newTimeIndex].getId() == "")
		{
			scheduler[doctorIndex][newDayIndex][newTimeIndex] = patients[doctorIndex][patientIndex];
			scheduler[doctorIndex][dayIndex][timeIndex] = Patient();
		}
		else
		{
			cout << endl << "TIME NOT AVAILABLE" << endl;
		}
	}
}

/* Pre:		string
 * Post:	int
 * Purpose: converts a day to the appropriate index
 *********************************************************/
int convertDayToInt(string day)
{
	int dayIndex;

	if (day == "Monday")
		dayIndex = 0;
	else if (day == "Tuesday")
		dayIndex = 1;
	else if (day == "Wednesday")
		dayIndex = 2;
	else if (day == "Thursday")
		dayIndex = 3;
	else if (day == "Friday")
		dayIndex = 4;

	return dayIndex;
}

/* Pre:		string
 * Post:	int
 * Purpose: converts a time to the appropriate index
 *********************************************************/
int convertTimeToInt(string time)
{
	int timeIndex;

	if (time == "9:00")
		timeIndex = 0;
	else if (time == "9:15")
		timeIndex = 1;
	else if (time == "9:30")
		timeIndex = 2;
	else if (time == "9:45")
		timeIndex = 3;
	else if (time == "10:00")
		timeIndex = 4;
	else if (time == "10:15")
		timeIndex = 5;
	else if (time == "10:30")
		timeIndex = 6;
	else if (time == "10:45")
		timeIndex = 7;
	else if (time == "11:00")
		timeIndex = 8;
	else if (time == "11:15")
		timeIndex = 9;
	else if (time == "11:30")
		timeIndex = 10;
	else if (time == "11:45")
		timeIndex = 11;
	else if (time == "12:00")
		timeIndex = 12;
	else if (time == "12:15")
		timeIndex = 13;
	else if (time == "12:30")
		timeIndex = 14;
	else if (time == "12:45")
		timeIndex = 15;
	else if (time == "13:00")
		timeIndex = 16;
	else if (time == "13:15")
		timeIndex = 17;
	else if (time == "13:30")
		timeIndex = 18;
	else if (time == "13:45")
		timeIndex = 19;
	else if (time == "14:00")
		timeIndex = 20;
	else if (time == "14:15")
		timeIndex = 21;
	else if (time == "14:30")
		timeIndex = 22;
	else if (time == "14:45")
		timeIndex = 23;
	else if (time == "15:00")
		timeIndex = 24;
	else if (time == "15:15")
		timeIndex = 25;
	else if (time == "15:30")
		timeIndex = 26;
	else if (time == "15:45")
		timeIndex = 27;
	else if (time == "16:00")
		timeIndex = 28;
	else if (time == "16:15")
		timeIndex = 29;
	else if (time == "16:30")
		timeIndex = 30;
	else if (time == "16:45")
		timeIndex = 31;
	else if (time == "17:00")
		timeIndex = 32;

	return timeIndex;
}


void displaySchedule(int doctorIndex, Patient ***&scheduler)
{
	
}

/* Pre:		3D Patient array, Doctor array, int
 * Post:	none
 * Purpose: loads patients from a text file into the 3D
 *			array
 *********************************************************/
void loadSchedule(Patient ***&scheduler, Doctor doctor[], int numberOfDoctor)
{
	ifstream fin;
	string id, name, address, phoneNumber, doctorId;

	fin.open(SCHEDULE_FILE);

	scheduler = new Patient**[numberOfDoctor];
	
	for (int i = 0; i < numberOfDoctor; i++)
	{
		scheduler[i] = new Patient*[NUMBER_OF_DAYS];
		
		for (int j = 0; j < NUMBER_OF_DAYS; j++)
		{
			scheduler[i][j] = new Patient[MAX_TIME_SLOTS];
		}
	}

	for (int doctor = 0; i < numberOfDoctor; doctor++)
	{
		for (int day = 0; day < NUMBER_OF_DAYS; day++)
		{
			for (int time = 0; time < MAX_TIME_SLOTS; time++)
			{
				getline(fin, id);
				if (id != "DNE")
				{
					scheduler[doctor][day][time].setId(id);
					getline(fin, name);
					scheduler[doctor][day][time].setName(name);
					getline(fin, address);
					scheduler[doctor][day][time].setAddress(address);
					getline(fin, phoneNumber);
					scheduler[doctor][day][time].setPhoneNumber(phoneNumber);
					getline(fin, doctorId);
					scheduler[doctor][day][time].setDoctorId(doctorId);

				}
				else
				{
					scheduler[doctor][day][time].setId("");
					scheduler[doctor][day][time].setName("");
					scheduler[doctor][day][time].setAddress("");
					scheduler[doctor][day][time].setPhoneNumber("");
					scheduler[doctor][day][time].setDoctorId("");
				}
			}
		}
	}

	fin.close();
}

/* Pre:		2D Patient array, Doctor array, int, 3D
 *			Patient Array
 * Post:	none
 * Purpose: gets appointment time, checks if patient 
 *			belongs to doctor, and removes appointment
 *********************************************************/
void removeAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor,
                       Patient ***&scheduler)
{
	int doctorIndex = -1;
	int dayIndex, timeIndex, patientIndex;
	bool patientToDoctor = false; // if patient has existing doctor
	string doctorName, patientId, time, day;

	cout << "Enter Doctor Name: ";
	getline(cin, doctorName);

	cout << "Enter Patient ID: ";
	getline(cin, patientId);

	for (int i = 0; i < numberOfDoctor; i++)
	{
		if (doctors[i].getName() == doctorName)
		{
			doctorIndex = i;
		}
	}

	for (int w = 0; w < doctors[doctorIndex].getNumberOfPatient; w++)
	{
		if (patients[doctorIndex][w].getId() == patientId)
		{
			patientIndex = w;
		}
	}


	if (patients[doctorIndex][patientIndex].getDoctorId() == doctors[doctorIndex].getId())
	{
		cout << "Enter Time: ";
		getline(cin, time);

		cout << "Enter Day: ";
		getline(cin, day);

		timeIndex = convertTimeToInt(time);
		dayIndex = convertDayToInt(day);

		if (scheduler[doctorIndex][dayIndex][timeIndex].getId() != "")
		{
			scheduler[doctorIndex][dayIndex][timeIndex] = Patient();
		}
		else
		{
			cout << endl << "PATIENT NOT FOUND" << endl;
		}
	}
}


int schedulerMenu()
{
   return 0;  //  this is a temporary code, must be replaced
}

void schedulerOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor,
                         Patient ***&scheduler)
{
}

/* Pre:		3D Patient array, int
 * Post:	none
 * Purpose: stores all patients into a text file based off
 *			of scheduler format
 *********************************************************/
void storeSchedule(Patient ***&scheduler, int numberOfDoctor)
{
	ofstream fout;

	fout.open(SCHEDULE_FILE);

	for (int doctor = 0; doctor < numberOfDoctor; doctor++)
	{
		for (int day = 0; day < NUMBER_OF_DAYS; day++)
		{
			for (int time = 0; time < MAX_TIME_SLOTS; time++)
			{
				if (scheduler[doctor][day][time].getId() != "")
				{
					fout << scheduler[doctor][day][time].getId();
					fout << scheduler[doctor][day][time].getName();
					fout << scheduler[doctor][day][time].getAddress();
					fout << scheduler[doctor][day][time].getPhoneNumber();
					fout << scheduler[doctor][day][time].getDoctorId();
				}
				else if (scheduler[doctor][day][time].getId() == "")
				{
					fout << "DNE";
				}
			}
		}
	}

	fout.close();
}


void viewSchedule(Doctor doctors[], int numberOfDoctor, Patient ***&scheduler)
{
}