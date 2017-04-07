#ifndef CONST_H
#define CONST_H

#include <iostream>
#include <string>

using namespace std;

const int  NUM_OF_TIME_SLOT = 28;
const string USER_FILE = "users.txt";
const string DATAFILE = "users.txt";
const string DOCTORS_FILE = "doctors.txt";
const string PATIENT_FILE = "patient.txt";

enum MAIN_MENU_OP { PATIENT_OP = 1, DOCTOR_OP, SCHEDULER, LOGOUT, EXIT };

#endif