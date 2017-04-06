#include "doctorOperations.h"
#include "constants.h"


void doctorOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
}


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
