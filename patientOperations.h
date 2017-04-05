#ifndef PATIENT_OP_H
#define PATIENT_OP_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "patient.h"
#include "doctor.h"
#include "doctorOperations.h"

using namespace std;

void addPatient(Patient **&patients, Doctor doctors[], int numberOfDoctor);
void getPatientIndex(Patient **patients, Doctor doctors[], int numberOfDoctor, string id,
                     int &patientIndex, int &doctorIndex);
bool isPatientExist(Patient **patients, Doctor doctors[],
                    int numberOfDoctor, string id);
void loadPatient(Patient *&patients, Doctor doctor);
int  patientMenu();
void patientOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor);
void removePatient(Patient **&patients, Doctor doctors[], int numberOfDoctor);
void searchPatient(Patient **patients, Doctor doctors[], int numberOfDoctor);
void storePatient(Patient patients[], Doctor doctors);
void updatePatient(Patient **patients, Doctor doctors[], int numberOfDoctor);


#endif
