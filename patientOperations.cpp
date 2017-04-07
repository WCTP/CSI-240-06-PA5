#include "patientOperations.h"
#include "constants.h"


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
	
	if (patientFound == false)
	{
		cout << endl << "PATIENT NOT FOUND" << endl;
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
	string id, name, address, phoneNumber, docID;
	ifstream fin;

	patients = new Patient[doctor.getNumberOfPatient()];

	fin.open(doctor.getId() + ".txt");
	
	if (fin.good())
	{
		for (int i = 0; i < doctor.getNumberOfPatient(); i++)
		{
			getline(fin, id);
			getline(fin, name);
			getline(fin, address);
			getline(fin, phoneNumber);
			getline(fin, docID);
			
			patients[i].setId(id);
			patients[i].setName(name);
			patients[i].setAddress(address);
			patients[i].setPhoneNumber(phoneNumber);
			patients[i].setDoctorId(doctor.getId());
		}
	}
	else
	{
		cout << endl << "FILE NOT FOUND" << endl;
	}

	fin.close();
}


int patientMenu()
{
	int userInput;

	system("cls");

	cout	<< "-----------------------------------------" << endl
			<< "-- JW Inc. Patient Management Services --" << endl
			<< "-----------------------------------------" << endl
			<< "-- 1.) Add Patient                     --" << endl
			<< "-- 2.) Remove Patient                  --" << endl
			<< "-- 3.) Search Patient                  --" << endl
			<< "-- 4.) Update Patient                  --" << endl
			<< "-- 5.) Exit                            --" << endl
			<< "-----------------------------------------" << endl
			<< "   Please Enter A Number: ";

	cin >> userInput;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return userInput;
}


void patientOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
	int selection;
	enum PATIENT_MENU_OP { ADD_PATIENT = 1, REMOVE_PATIENT, SEARCH_PATIENT, UPDATE_PATIENT, EXIT };

	do
	{
		selection = patientMenu();

		if (selection == ADD_PATIENT)
		{
			addPatient(patients, doctors, numberOfDoctor);
		}
		else if (selection == REMOVE_PATIENT)
		{
			removePatient(patients, doctors, numberOfDoctor);
		}
		else if (selection == SEARCH_PATIENT)
		{
			searchPatient(patients, doctors, numberOfDoctor);
		}
		else if (selection == UPDATE_PATIENT)
		{
			updatePatient(patients, doctors, numberOfDoctor);
		}
	} while (selection != EXIT);
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
				row--;
				col--;
			}
		}
	}

	if (patientFound == true)
	{
		
		patients[row][col].display();
		doctors[row].display();
		system("pause");
	}
}


void storePatient(Patient patients[], Doctor doctor)
{
	string id, name, address, phoneNumber;
	ofstream fout;

	fout.open(doctor.getId() + ".txt");

	if (fout.good())
	{
		for (int i = 0; i < doctor.getNumberOfPatient(); i++)
		{
			fout << patients[i].getId() << '\n'
				<< patients[i].getName() << '\n'
				<< patients[i].getAddress() << '\n'
				<< patients[i].getPhoneNumber() << '\n'
				<< doctor.getId() << '\n';
		}
	}
	else
	{
		cout << endl << "FILE NOT FOUND" << endl;
	}

	fout.close();
}


void updatePatient(Patient **patients, Doctor doctors[], int numberOfDoctor)
{
	int row, col;
	string id, name;
	bool patientFound = false;

	cout << "Patient ID: ";
	getline(cin, id);

	for (row = 0; row < numberOfDoctor && patientFound == false; row++)
	{
		for (col = 0; col < doctors[row].getNumberOfPatient() && patientFound == false; col++)
		{
			if (id == patients[row][col].getId())
			{
				row--;
				col--;
				patientFound = true;
			}
		}
	}

	if (patientFound == true)
	{
		cout << "Enter Name: ";
		getline(cin, name);

		patients[row][col].setName(name);

		cout << endl << "name updated" << endl;
	}
	else
	{
		cout << endl << "ERROR: PATIENT NOT FOUND" << endl;
	}
}