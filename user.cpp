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

#include "user.h"

/* Pre:		none
 * Post:	none
 * Purpose: default constructor
 *********************************************************/
User::User()
{
	mAccounts = NULL;
	mAccountInUsed = 0;
}

/* Pre:		none
 * Post:	none
 * Purpose: constructor
 *********************************************************/
User::User(const User& obj)
{
	if (mAccounts != NULL)
	{
		delete[] mAccounts;
	}

	mAccounts = new Account[obj.mAccountInUsed];

	for (int i = 0; i < obj.mAccountInUsed; i++)
	{
		mAccounts[i].mId = obj.mAccounts[i].mId;
		mAccounts[i].mId = obj.mAccounts[i].mPassword;
	}

	mAccountInUsed = obj.mAccountInUsed;
}

/* Pre:		none
 * Post:	none
 * Purpose: deconstructor
 *********************************************************/
User::~User()
{
	if (mAccounts != NULL)
	{
		delete[] mAccounts;
		mAccounts = NULL;
	}
	
	mAccountInUsed = 0;
}

/* Pre:		int
 * Post:	Account
 * Purpose: retrieves account from dynamic array
 *********************************************************/
Account User::getAccount(int index)
{
	return mAccounts[index];
}

/* Pre:		none
 * Post:	int
 * Purpose: retrieves accounts in use
 *********************************************************/
int User::getAccountInUsed()
{
	return mAccountInUsed;
}

/* Pre:		int
 * Post:	string
 * Purpose: retrieves account ID
 *********************************************************/
string User::getID(int index)
{
	return mAccounts[index].mId;
}

/* Pre:		int
 * Post:	string
 * Purpose: retrieves account password
 *********************************************************/
string User::getPassword(int index)
{
	return mAccounts[index].mPassword;
}

/* Pre:		int, Account
 * Post:	nnone
 * Purpose: update array with specified Account
 *********************************************************/
void User::setAccount(int index, Account obj)
{
	mAccounts[index] = obj;
}

/* Pre:		int, string
 * Post:	none
 * Purpose: update array with specified ID
 *********************************************************/
void User::setID(int index, string id)
{
	mAccounts[index].mId = id;
}

/* Pre:		int, string
 * Post:	none
 * Purpose: update array with specified password
 *********************************************************/
void User::setPassword(int index, string password)
{
	mAccounts[index].mPassword = password;
}

/* Pre:		Account
 * Post:	bool
 * Purpose: checks array to see if there is an account
 *			similar to the one provided
 *********************************************************/
bool User::isUserExist(Account obj)
{
	bool doesExist = false;

	for (int i = 0; i < mAccountInUsed; i++)
	{
		if (mAccounts[i] == obj)
		{
			doesExist = true;
		}
	}

	return doesExist;
}

/* Pre:		string
 * Post:	none
 * Purpose: creates dynamic array and loads file into 
 *			array
 *********************************************************/
void User::loadData(string dataFile)
{
	ifstream fin;
	fin.open(dataFile);
	
	if (fin.good())
	{
		fin >> mAccountInUsed;
		fin.ignore();

		mAccounts = new Account[mAccountInUsed];
		for (int i = 0; i < mAccountInUsed && !fin.eof(); i++)
		{
			fin >> mAccounts[i];
		}
	}
	else
	{
		cout << "ERROR, FILE NOT FOUND" << endl;
	}
	
	fin.close();
}

/* Pre:		string
 * Post:	none
 * Purpose: stores data from array of Accounts into a text
 *			file
 *********************************************************/
void User::storeData(string dataFile)
{
	ofstream fout;

	fout.open(dataFile);
	
	fout << mAccountInUsed << '\n';
	for (int i = 0; i < mAccountInUsed; i++)
	{
		fout << mAccounts[i];
	}

	fout.close();
}

/* Pre:		Account
 * Post:	bool
 * Purpose: checks array to see if there is an account
 *			similar to the one provided
 *********************************************************/
bool User::validateLogin(Account obj) const
{
	bool doesExist = false;
	
	for (int i = 0; i < mAccountInUsed; i++)
	{
		cout << mAccounts[i].mId;
		if (mAccounts[i] == obj)
		{
			cout << "HELLO";
			if (mAccounts[i].mPassword == obj.mPassword)
			{
				doesExist = true;
			}
			
		}
	}

	return doesExist;
}