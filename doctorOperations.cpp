#include "doctorOperations.h"


void doctorOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor)
{
}


int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string name)
{
	int index;

	for (index = 0; i < numberOfDoctor; i++)
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

	for (int i = 0; i < numberOfDoctor && doesExist = false; i++)
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
	

	return 0; 
}


void storeDoctor(Doctor doctors[], int numberOfDoctor)
{
}
