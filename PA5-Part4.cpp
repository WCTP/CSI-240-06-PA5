#include "header.h"

int main()
{
	Doctor  *doctors = NULL;
	Patient **patients = NULL;
	int     numberOfDoctor, selection, i = 1, j = 1, patientIndex = -1, doctorIndex = -1;
	User    users;

	/* TESTING DOCTOR OPERATIONS */

	numberOfDoctor = loadDoctor(doctors);

	cout << endl << "Displaying doctors: " << endl;

	for (int i = 0; i < numberOfDoctor; i++)
	{
		doctors[i].display();
	}

	cout << endl << "Expecting True: " << isDoctorExist(doctors, numberOfDoctor, "Sarah Goodman") << endl;

	cout << endl << "Expecting One: " << getDoctorIndex(doctors, numberOfDoctor, "Sarah Goodman") << endl;

	cout << endl << "Storing Doctor Data..." << endl;
	storeDoctor(doctors, numberOfDoctor);

	system("pause");

	doctorOperations(patients, doctors, numberOfDoctor);

	system("cls");

	/* TESTING PATIENT OPERATIONS */

	cout << endl << "Loading Patients..." << endl;
	
	patients = new Patient*[numberOfDoctor];

	for (i = 0; i < numberOfDoctor; i++)
	{
		patients[i] = NULL;
		loadPatient(patients[i], doctors[i]);
	}

	cout << endl << "Displaying Patients: " << endl;

	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int c = 0; c < doctors[i].getNumberOfPatient(); c++)
		{
			patients[i][c].display();
			cout << endl;
		}
	}

	cout << endl << "Expecting True: " << isPatientExist(patients, doctors, numberOfDoctor, "123-12-1234");

	cout << endl << "Expecting Zero and Zero: ";
	getPatientIndex(patients, doctors, numberOfDoctor, "123-45-6789", patientIndex, doctorIndex);
	cout << patientIndex << " " << doctorIndex << endl;

	cout << endl << "Search For 123-12-1234: ";
	searchPatient(patients, doctors, numberOfDoctor);

	cout << endl << "Updating Patient, ID is 123-12-1234: " << endl;
	updatePatient(patients, doctors, numberOfDoctor);

	cout << endl << "Displaying Patients: " << endl;

	for (int i = 0; i < numberOfDoctor; i++)
	{
		for (int c = 0; c < doctors[i].getNumberOfPatient(); c++)
		{
			patients[i][c].display();
			cout << endl;
		}
	}

	cout << endl << "Storing Patients..." << endl;
	for (i = 0; i < numberOfDoctor; i++)
		storePatient(patients[i], doctors[i]);

	cout << endl << "Deleting Pointers..." << endl;
	
	if (doctors != NULL)
		delete[] doctors;


	for (int w = 0; i < numberOfDoctor; i++)
	{
		if (patients[w] != NULL)
			delete[] patients[i];
	}
	delete[] patients;


	cout << endl << endl;
	system("pause");
	return 0;
}