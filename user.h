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
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "account.h"

using namespace std;

class User {
	private:
		Account *mAccounts;
		int mAccountInUsed;
	public:
		User();
		User(const User& obj);
		
		~User();
		
		Account getAccount(int index);
		int getAccountInUsed();
		string getID(int index);
		string getPassword(int index);

		void setAccount(int index, Account obj);
		void setID(int index, string id);
		void setPassword(int index, string password);

		bool isUserExist(Account obj);
		void loadData(string dataFile);
		void storeData(string dataFile);
		bool validateLogin(Account obj) const;

};

#endif USER_H