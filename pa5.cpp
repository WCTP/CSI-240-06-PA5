#include "header.h"

/*
int main()
{
   Doctor  *doctors = NULL;
   Patient **patients = NULL;
   Patient ***scheduler = NULL;
   int     numberOfDoctor, selection, i, j;
   User    users;

   numberOfDoctor = loadDoctor(doctors);

   patients = new Patient*[numberOfDoctor];

   for (i = 0; i < numberOfDoctor; i++)
   {
      patients[i] = NULL;
      loadPatient(patients[i], doctors[i]);
   }

   loadSchedule(scheduler, doctors, numberOfDoctor);

   users.loadData(USER_FILE);

   do
   {
      login(users);

      do
      {
         selection = mainMenu();

         if (selection == PATIENT_OP)
            patientOperations(patients, doctors, numberOfDoctor);

         else if (selection == DOCTOR_OP)
            doctorOperations(patients, doctors, numberOfDoctor);

         else if (selection == SCHEDULER)
            schedulerOperations(patients, doctors, numberOfDoctor, scheduler);
      }  while (selection != EXIT && selection != LOGOUT);
   } while (selection != EXIT);

   storeDoctor(doctors, numberOfDoctor);

   for (i = 0; i < numberOfDoctor; i++)
      storePatient(patients[i], doctors[i]);

   storeSchedule(scheduler, numberOfDoctor);

   users.storeData(USER_FILE);

   if (doctors != NULL)
      delete[] doctors;

   for (i = 0; i < numberOfDoctor; i++)
   {
      if (patients[i] != NULL)
         delete[] patients[i];
   }

   delete[] patients;

   for (i = 0; i < numberOfDoctor; i++)
   {
      //for (j = 0; j < NUM_OF_TIME_SLOT; j++)
		  //delete [] scheduler[i][j];
   }

   for (i = 0; i < numberOfDoctor; i++)
      //delete [] scheduler[i];

   //delete [] scheduler;


   return 0;
}*/