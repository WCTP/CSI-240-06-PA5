#include "doctorOperations.h"
#include "constants.h"

/* Pre:		none
 * Post:	int
 * Purpose: displays Doctor menu and gets input, which is
 *			returned
 *********************************************************/
int doctorMenu()
{
	int userInput;

	system("cls");

	cout << "-----------------------------------------" << endl
		<< "-- JW Inc. Patient Management Services --" << endl
		<< "-----------------------------------------" << endl
		<< "-- 1.) Get Doctor Index                --" << endl
		<< "-- 2.) Check Doctor Existance          --" << endl
		<< "-- 3.) Exit                            --" << endl
		<< "-----------------------------------------" << endl
		<< "   Please Enter A Number: ";

	cin >> userInput;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return userInput;
}

/* Pre:		2D Patient array, Doctor array, int
 * Post:	none
 * Purpose: queries user for input and calls proper
 *			function based off of doctorMenu()
 *********************************************************/
void doctorOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
	int selection;
	bool existance;
	string name;
	enum DOCTOR_MENU_OP { GET_DOCTOR_INDEX = 1, CHECK_DOCTOR_EXISTANCE, EXIT };

	do
	{
		selection = doctorMenu();

		if (selection == GET_DOCTOR_INDEX)
		{
			cout << endl << "ENTER NAME OF DOCTOR: ";
			getline(cin, name);
			cout << "Index: " << getDoctorIndex(doctors, numberOfDoctor, name) << endl;
			system("pause");
		}
		else if (selection == CHECK_DOCTOR_EXISTANCE)
		{
			cout << endl << "ENTER NAME OF DOCTOR: ";
			getline(cin, name);
			existance = isDoctorExist(doctors, numberOfDoctor, name);
			if (existance)
				cout << "Doctor is in the system." << endl;
			else
				cout << "Doctor is not in the system." << endl;
			system("pause");
		}
	} while (selection != EXIT);
}

/* Pre:		Doctor array, int, string
 * Post:	int
 * Purpose: finds the Doctor index in the Doctor array and
 *			returns index
 *********************************************************/
int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string name)
{
	int index = -1;

	for (int i = 0; i < numberOfDoctor && index != i; i++)
	{
		if (doctors[i].getName() == name)
		{
			index = i;
		}
   }

	return index;
}

/* Pre:		Doctor array, int, string
 * Post:	bool
 * Purpose: finds Doctor in Doctor array and returns 
 *			confirmation of Doctor being successfully 
 *			found
 *********************************************************/
bool isDoctorExist(Doctor doctors[], int numberOfDoctor, string name)
{
	bool doesExist = false;

	for (int i = 0; i < numberOfDoctor && doesExist == false; i++)
	{
		if (doctors[i].getName() == name)
		{
			doesExist = true;
		}
	}

	return doesExist;
}

/* Pre:		Doctor array
 * Post:	int
 * Purpose: takes Doctor information from a text file and
 *			loads up information into Doctor array
 *********************************************************/
int loadDoctor(Doctor *&doctors)
{
	int numDoctors, index, numOfPatients;
	string name, id;
	ifstream fin;

	fin.open(DOCTORS_FILE);

	if (fin.good())
	{
		fin >> numDoctors;
		fin.ignore();
		
		doctors = new Doctor[numDoctors];
		
		for (int i = 0; i < numDoctors; i++)
		{
			getline(fin, name);
			doctors[i].setName(name);

			getline(fin, id);
			doctors[i].setId(id);

			fin >> index;
			doctors[i].setIndex(index);

			fin >> numOfPatients;
			doctors[i].setNumberOfPatient(numOfPatients);
			
			fin.ignore();
		}
	}
	else
	{
		cout << "FILE DOESN'T EXIST";
	}

	fin.close();

	return numDoctors; 
}

/* Pre:		Doctor array, int
 * Post:	none
 * Purpose: takes doctor array and stores in a text file
 *********************************************************/
void storeDoctor(Doctor doctors[], int numberOfDoctor)
{
	ofstream fout;

	fout.open(DOCTORS_FILE);

	if (fout.good())
	{
		fout << numberOfDoctor;
		
		for (int i = 0; i < numberOfDoctor; i++)
		{
			fout << '\n';
			fout << doctors[i].getName() << '\n';
			fout << doctors[i].getId() << '\n';
			fout << doctors[i].getIndex() << " "
				<< doctors[i].getNumberOfPatient();
		}
	}
	else
	{
		cout << "FILE NOT FOUND";
	}

	fout.close();
}