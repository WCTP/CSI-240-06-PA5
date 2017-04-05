#ifndef DOCTOR_OP_H
#define DOCTOR_OP_H

#include <iostream>
#include <fstream>
#include <string>
#include "doctor.h"
#include "patient.h"

using namespace std;

void doctorOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor);
int  getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName);
bool isDoctorExist(Doctor doctors[], int numberOfDoctor, string doctorName);
int  loadDoctor(Doctor *&doctors);
void storeDoctor(Doctor doctors[], int numberOfDoctor);

#endif
