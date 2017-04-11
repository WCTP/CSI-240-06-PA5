#include "patientOperations.h"
#include "constants.h"

/* Pre:		a 2D Patient array, an array of Doctor, 
 *			and an int of how many doctors are in the 
 *			Doctor array
 * Post:	a patient at a certain row will be created 
 *			in the patients array
 * Purpose: to add a patient to the 2D patients array
 *********************************************************/
void addPatient(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
	Patient patientToAdd;
	Patient *temp;
	string docName;
	int row, col;
	int i;

	cout << "Enter the patient's information." << endl;
	cin >> patientToAdd;

	cout << "Enter the Doctor's Name." << endl;
	getline(cin, docName);
	
	if (isPatientExist(patients, doctors, numberOfDoctor, patientToAdd.getId()) != true && isDoctorExist(doctors, numberOfDoctor, docName) == true)
	{
		row = getDoctorIndex(doctors, numberOfDoctor, docName);

		temp = new Patient[doctors[row].getNumberOfPatient() + 1];

		for (i = 0; i < doctors[row].getNumberOfPatient(); i++)
		{
			temp[i] = patients[row][i];
		}

		temp[i] = patientToAdd;
		delete[] patients[row];

		patients[row] = temp;
		delete[] temp;

		cout << "Patient successfully added!!" << endl;
	}
}

/* Pre:		2D dynamic Patient array, Doctor array, int,
 *			string, int&, int&
 * Post:	patientIndex, doctorIndex
 * Purpose: find if a patient exists in the 2D array and
 *			return the indexes via reference passing
 *********************************************************/
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

/* Pre:		2D dynamic Patient array, Doctor array, int,
 *			string
 * Post:	bool
 * Purpose: searches patient array and returns whether or
 *			not the patient exists in the array
 *********************************************************/
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

/* Pre:		Patient array, Doctor
 * Post:	none
 * Purpose: load patients from a text file into the array
 *********************************************************/
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

/* Pre:		none
 * Post:	int
 * Purpose: display the patient menu and get user input,
 *			and then return the input
 *********************************************************/
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

/* Pre:		2D Patient array, Doctor array, int
 * Post:	none
 * Purpose: decide function to call based off of the
 *			patient menu
 *********************************************************/
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

/* Pre:		a 2D Patient array, an array of Doctor, 
 *			and an int of how many doctors
 * Post:	a patient at a certain row will be removed 
 *			in the patients array
 * Purpose: to remove a patient from the 2D patients array
 *********************************************************/
void removePatient(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
	Patient patientToRemove;
	string id;
	Patient *temp;
	int row, col;
	int docIndex;
	int i;
	bool found;

	cout << "Enter the patient's id to remove." << endl;
	getline(cin, id);

	if (isPatientExist(patients, doctors, numberOfDoctor, id) == true)
	{
		for (row = 0; row < numberOfDoctor; row++)
		{
			for (col = 0; col < doctors[row].getNumberOfPatient(); col++)
			{
				cout << doctors[row].getNumberOfPatient() << endl;

				if (patients[row][col] == id)
				{
					found = true;
					patients[row][col].setId("");
					break;
				}
			}

			if (found == true)
			{
				break;
			}
		}

		temp = new Patient[doctors[row].getNumberOfPatient() - 1];

		for (i = 0; i < doctors[row].getNumberOfPatient(); i++)
		{
			if (patients[row][i].getId() != "")
			{
				temp[i] = patients[row][i];
			}
		}

		int subtract = doctors[row].getNumberOfPatient();
		subtract--;

		doctors[row].setNumberOfPatient(subtract);
		delete[] patients[row];

		patients[row] = temp;
		delete[] temp;

		cout << "Patient successfully removed!!" << endl;

	}
}

/* Pre:		2D Patient array, Doctor array, int
 * Post:	none
 * Purpose: asks user for ID to search patient and display
 *			if they exist in the array
 *********************************************************/
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
	else
	{
		cout << endl << "PATIENT NOT FOUND" << endl;
	}
}

/* Pre:		Patient array, Doctor
 * Post:	none
 * Purpose: stores Patient array into a text file based
 *			off of Doctor id
 *********************************************************/
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

/* Pre:		2D Patient array, Doctor array, int
 * Post:	none
 * Purpose: get user input of ID of patient to change,
 *			get new name, and change name of specified 
 *			patient
 *********************************************************/
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