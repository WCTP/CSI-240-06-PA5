#include "header.h"

void login(User users)
{
	string username, password;
	bool loginSuccess = false;
	Account userAccount;
	
	while (loginSuccess == false)
	{
		cout << "Username: ";
		getline(cin, username);

		cout << "Password: ";
		getline(cin, password);
		
		userAccount.mId = username;
		userAccount.mPassword = password;

		loginSuccess = users.validateLogin(userAccount);

		system("pause");
		system("cls");
	}
}


int mainMenu()
{
	int userInput;
	
	cout	<< "-----------------------------------------" << endl
			<< "-- JW Inc. Patient Management Services --" << endl
			<< "-----------------------------------------" << endl
			<< "-- 1.) Patient Operator                --" << endl
			<< "-- 2.) Doctor Operator                 --" << endl
			<< "-- 3.) Scheduler                       --" << endl
			<< "-- 4.) Logout                          --" << endl
			<< "-- 5.) Exit                            --" << endl
			<< "-----------------------------------------" << endl
			<< "   Please Enter A Number: " << endl;

	cin >> userInput;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return userInput;
}



