/*		Author: Walter Proulx
 *		Class : CSI 240-06
 *		Assignment : PA 5
 *		Date Assigned : March 24, 2017
 *		Due Date : March 27, 2017
 *		Description :
 *			A program for a clinic to track a patient's information.
 *
 *		Certification of Authenticity :
 *			I certify that this is entirely my own work, except where I have given
 *			fully - documented references to the work of others.I understand the
 *			definition and consequences of plagiarism and acknowledge that the assessor
 *			of this assignment may, for the purpose of assessing this assignment :
 *				-	Reproduce this assignment and provide a copy to another member of
 *					academic staff; and / or
 *				-	Communicate a copy of this assignment to a plagiarism checking
 *					service(which may then retain a copy of this assignment on its
 *					database for the purpose of future plagiarism checking)
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Account {
	string mId, mPassword;

	Account();
	Account(string id, string password);

	~Account();

	bool operator==(Account rhs);
	bool operator!=(Account rhs);

	friend istream& operator>>(istream& input, Account& obj);
	friend ostream& operator<<(ostream& output, Account& obj);
};

#endif ACCOUNT_H