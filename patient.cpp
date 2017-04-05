/*
Author: Ashton Allen
Class : CSI-240-06
Assignment : PA5 Part 2
Date Assigned : 3/28/17
Due Date : 3/31/17 at 9:30am
Description : This is the backend of a program
A brief description of the purpose of the program.
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment :
-Reproduce this assignment and provide a copy to another member of academic staff; and / or
-Communicate a copy of this assignment to a plagiarism checking service(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include "Patient.h"

/* Pre: None
* Post: None
* Purpose: Ser initial values
*********************************************************/
Patient::Patient()
{
	setId("");
	mName = "";
	mAddress = "";
	mPhoneNumber = "";
	mDoctorId = "";
}

/* Pre: takes strings for each value
* Post: None
* Purpose: Set object values to values given
*********************************************************/
Patient::Patient(string id, string name, string address, string phoneNumber, string doctorId)
{
	setId(id);
	mName = name;
	mAddress = address;
	mPhoneNumber = phoneNumber;
	mDoctorId = doctorId;
}

Patient::Patient(const Patient& obj)
{
	mName = obj.mName;
	mAddress = obj.mAddress;
	mPhoneNumber = obj.mAddress;
//	mDoctorId = obj.getDoctorId(); //dont have access to these yet
//	setId(obj.getId());
}

/* Pre: None
* Post: None
* Purpose: Destroy object
*********************************************************/
Patient::~Patient()
{
	//not sure exactly what should be here quite yet
}

/* Pre: None
* Post: return doctor id
* Purpose: get doctor id
*********************************************************/
string Patient::getDoctorId()
{
	return mDoctorId;
}

/* Pre: None
* Post: None
* Purpose: Set doctor id to given id
*********************************************************/
void Patient::setDoctorId(string id)
{
	mDoctorId = id;
}

/* Pre: None
* Post: None
* Purpose: Wasn't exactly sure what this was supposed to do so i had it display info pertaining to object
*********************************************************/
void Patient::display()
{
	cout << "Name: " << mName << endl
		<< "Address: " << mAddress << endl
		<< "Phone Number: " << mPhoneNumber << endl
		<< "Id: " << getId() << endl
		<< "Doctor Id: " << mDoctorId << endl;
}

/* Pre: istream and patient object
* Post: None
* Purpose: overload >> to take in data
*********************************************************/
istream& operator>>(istream& input, Patient& obj)
{
	string tempId;
	
	getline(input, tempId);
	getline(input, obj.mName);
	getline(input, obj.mAddress);
	getline(input, obj.mPhoneNumber);
	getline(input, obj.mDoctorId);

	obj.setId(tempId);

	return input;
}

/* Pre: ostream and patient object
* Post: None
* Purpose: Overload << to output obj information
*********************************************************/
ostream& operator<<(ostream& output, Patient& obj)
{
	output << obj.mName << endl
		<< obj.mAddress << endl
		<< obj.mPhoneNumber << endl
		<< obj.getId() << endl
		<< obj.mDoctorId << endl;

	return output;
}
