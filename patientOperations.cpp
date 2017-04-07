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
	string id, name, address, phoneNumber, fileName;
	ifstream fin;

	patients = new Patient[doctor.getNumberOfPatient()];

	fileName = doctor.getId() + ".txt";

	fin.open(fileName);
	
	if (fin.good())
	{
		for (int i = 0; i < doctor.getNumberOfPatient(); i++)
		{
			getline(fin, id);
			getline(fin, name);
			getline(fin, address);
			getline(fin, phoneNumber);
			
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
	string id, name, address, phoneNumber;
	ofstream fin;

	fin.open(doctor.getId());

	if (fin.good())
	{
		for (int i = 0; i < doctor.getNumberOfPatient(); i++)
		{
			fin << patients[i].getId() << '\n'
				<< patients[i].getName() << '\n'
				<< patients[i].getAddress() << '\n'
				<< patients[i].getPhoneNumber() << '\n'
				<< doctor.getId();
		}
	}
	else
	{
		cout << endl << "FILE NOT FOUND" << endl;
	}

	fin.close();
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