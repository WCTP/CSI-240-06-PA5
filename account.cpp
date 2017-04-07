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

#include "account.h"

/* Pre:		none
 * Post:	none
 * Purpose: default constructor
 *********************************************************/
Account::Account()
{
	mId = "";
	mPassword = "";
}

/* Pre:		none
 * Post:	none
 * Purpose: constructor
 *********************************************************/
Account::Account(string id, string password)
{
	mId = id;
	mPassword = password;
}

/* Pre:		none
 * Post:	none
 * Purpose: deconstructor
 *********************************************************/
Account::~Account()
{
	/* left blank intentionally */
}

/* Pre:		Account
 * Post:	bool
 * Purpose: allows two accounts to be evaluated as equal
 *********************************************************/
bool Account::operator==(Account rhs)
{
	return (mId == rhs.mId);
}

/* Pre:		Account
 * Post:	bool
 * Purpose: allows two accounts to be evaluated as not 
 *			equal
 *********************************************************/
bool Account::operator!=(Account rhs)
{
	bool isDiff = true;

	if (mId == rhs.mId)
	{
		isDiff = false;
	}

	return isDiff;
}

/* Pre:		none
 * Post:	none
 * Purpose: allows input stream to directly intialize an
 *			account
 *********************************************************/
istream& operator>>(istream& input, Account& obj)
{
	getline(input, obj.mId, ' ');
	getline(input, obj.mPassword);

	return input;
}

/* Pre:		none
 * Post:	none
 * Purpose: allows output stream to display an account 
 *			object
 *********************************************************/
ostream& operator<<(ostream& output, Account& obj)
{
	output << obj.mId << " " << obj.mPassword << endl;

	return output;
}

