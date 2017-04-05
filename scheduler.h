#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "doctor.h"
#include "patient.h"
#include "doctorOperations.h"
#include "patientOperations.h"

using namespace std;

void addAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor,
                    Patient ***&scheduler);
void displaySchedule(int doctorIndex, Patient ***&scheduler);
void loadSchedule(Patient ***&scheduler, Doctor doctor[], int numberOfDoctor);
void removeAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor,
                       Patient ***&scheduler);
int  schedulerMenu();
void schedulerOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor,
                         Patient ***&scheduler);
void storeSchedule(Patient ***&scheduler, int numberOfDoctor);
void viewSchedule(Doctor doctors[], int numberOfDoctor, Patient ***&scheduler);

#endif