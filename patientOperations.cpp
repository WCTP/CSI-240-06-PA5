#include "patientOperations.h"


void addPatient(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
}


void getPatientIndex(Patient **patients, Doctor doctors[], int numberOfDoctor, string id,
                     int &patientIndex, int &doctorIndex)
{
	bool patientFound = false;
	int row, col;
	

	for (row = 0; row < numberOfDoctor && patientFound == false; row++)
	{
		for (col = 0; col < doctors[row].getNumberOfPatient() && patientFound == false; col++)
		{
			if (id == patients[row][col].getId())
			{
				patientFound = true;
				patientIndex = col;
				doctorIndex = row;
			}
		}
	}
}


bool isPatientExist(Patient **patients, Doctor doctors[], int numberOfDoctor,
                    string id)
{
	bool doesExist = false;
	int col, row;

	for (row = 0; row < numberOfDoctor && doesExist == false; row++)
	{
		for (col = 0; col < doctors[row].getNumberOfPatient() && doesExist == false; col++)
		{
			if (id == patients[row][col].getId())
			{
				doesExist = true;
			}
		}
	}

	return doesExist;
}


void loadPatient(Patient *&patients, Doctor doctor)
{
}


int patientMenu()
{
   return 0;  //  this is a temporary code, must be replaced
}


void patientOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
}


void removePatient(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
}


void searchPatient(Patient **patients, Doctor doctors[], int numberOfDoctor)
{
	int row, col;
	string id;
	bool patientFound = false;

	cout << "Please enter SSN: ";
	getline(cin, id);

	for (row = 0; row < numberOfDoctor && patientFound == false; row++)
	{
		for (col = 0; col < doctors[row].getNumberOfPatient() && patientFound == false; col++)
		{
			if (id == patients[row][col].getId())
			{
				patientFound = true;
			}
		}
	}

	patients[row][col].display();
	doctors[row].display();
}


void storePatient(Patient patients[], Doctor doctor)
{
}


void updatePatient(Patient **patients, Doctor doctors[], int numberOfDoctor)
{
}