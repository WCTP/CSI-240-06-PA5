#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <conio.h>  
#include "doctor.h"
#include "patient.h"
#include "doctorOperations.h"
#include "patientOperations.h"
#include "scheduler.h"
#include "user.h"
#include "constants.h"

using namespace std;


//  general operations
void login(User users);
int  mainMenu();


#endif