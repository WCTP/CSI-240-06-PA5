//  filename:  doctor.h

/*
Author:  Wei Kian Chen
Class:  CSI-240-06
Assignment: PA 5
Date Assigned: obmitted
Due Date: obmitted

Description:
Simulating a database for clinic.

The purpose of this file is to declare the Doctor class, which inherit from Person

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment may, for
the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service(which may then
retain a copy of this assignment on its database for the purpose of future plagiarism
checking)
*/

#ifndef _DOCTOR_H
#define _DOCTOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;


class Doctor : public Person
{
   private:
      int mIndex, mNumberOfPatient;

   public:
      Doctor();
      Doctor(string id, string name, string address, string phoneNumber, int index,
             int patientCount);
      Doctor(const Doctor &obj);
      ~Doctor();

      //  assessor
      int getIndex();
      int getNumberOfPatient();

      //  mutator
      void setIndex(int index);
      void setNumberOfPatient(int patientCount);

      Doctor operator++(int);
      Doctor operator--(int);

      // virtual function
      virtual void display();

      //  friend functions
      friend istream& operator>>(istream &input, Doctor &obj);
      friend ostream& operator<<(ostream &output, Doctor obj);
};


#endif