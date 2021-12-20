/*
* Gavin Brown
* CSC210 - Fall 2021
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <conio.h>
using namespace std;

								//Initializing global variables for storing clock data.
int TWELVETIME_SECONDS;
int TWELVETIME_MINUTES;
int TWELVETIME_HOURS;

int TWENTYTIME_SECONDS;
int TWENTYTIME_MINUTES;
int TWENTYTIME_HOURS;

//Building the clock menu display.
//Runs a clock and stores the integer data in the global clock variables, also splits the integers into 24-hour and 12-hour time.
void clockcode()
{
	for (TWENTYTIME_HOURS; TWENTYTIME_HOURS < 24; TWENTYTIME_HOURS++)
	{
		for (TWENTYTIME_MINUTES; TWENTYTIME_MINUTES < 60; TWENTYTIME_MINUTES++)
		{
			for (TWENTYTIME_SECONDS; TWENTYTIME_SECONDS < 60; TWENTYTIME_SECONDS++)
			{
				TWELVETIME_SECONDS = TWENTYTIME_SECONDS;

			//	cout << "24-Clock: " << TWENTYTIME_HOURS << "::" << TWENTYTIME_MINUTES << "::" << TWENTYTIME_SECONDS << endl;
				//cout << "12-Clock: " << TWELVETIME_HOURS << "::" << TWELVETIME_MINUTES << "::" << TWELVETIME_SECONDS << endl;

				Sleep(1000);
			}
			TWELVETIME_MINUTES++;

			TWENTYTIME_SECONDS = 0;
			TWELVETIME_SECONDS = 0;
		}
		TWELVETIME_HOURS++;


		TWENTYTIME_MINUTES = 0;
		TWELVETIME_MINUTES = 0;
	}
	//return;
}

//int TWELVETIME_HOURS, int TWELVETIME_MINUTES, int TWELVETIME_SECONDS, int TWENTYTIME_HOURS, int TWENTYTIME_MINUTES, int TWENTYTIME_SECONDS
//int TWENTYTIME_HOURS, int TWENTYTIME_MINUTES, int TWENTYTIME_SECONDS

void clockdisplay()
{
	if (TWELVETIME_HOURS > 12)												//Testing for afternoon hours
	{
		TWELVETIME_HOURS = TWELVETIME_HOURS - 12;
	}

	if (TWENTYTIME_HOURS > 24)												//Testing for a new day
	{
		TWENTYTIME_HOURS = 1;
	}

	if (TWENTYTIME_MINUTES > 59)
	{
		TWENTYTIME_HOURS++;
		TWELVETIME_HOURS++;

		TWELVETIME_MINUTES = 0;
		TWENTYTIME_MINUTES = 0;
	}

	if (TWENTYTIME_SECONDS > 59)
	{
		TWENTYTIME_MINUTES++;
		TWELVETIME_MINUTES++;

		TWENTYTIME_SECONDS = 0;
		TWELVETIME_SECONDS = 0;
	}

	system("CLS");															//Refresh the console

	cout << "*****************************************************" << endl;
	cout << "*****************************************************" << endl;
	cout << "*******  12 - HOUR CLOCK  **  24 - HOUR CLOCK  ******" << endl;
	cout << "************" << TWELVETIME_HOURS << "::" << TWELVETIME_MINUTES << "::" << TWELVETIME_SECONDS << "*************" << TWENTYTIME_HOURS << "::" << TWENTYTIME_MINUTES << "::" << TWENTYTIME_SECONDS << "**************" << endl;
	cout << "*****************************************************" << endl;
	cout << "*****************************************************" << endl;
	cout << "               * 1 - Add One Hour   *            " << endl;
	cout << "               * 2 - Add One Minute *            " << endl;
	cout << "               * 3 - Add One Second *            " << endl;
	cout << "               * 4 - Exit Program   *            " << endl;
	cout << "*****************************************************" << endl;

	Sleep(1000);
	clockdisplay();

}

void clockmenu()
{

	while(1)
	{



		int user_number = 0;													//Variable for holding user input

		cin >> user_number;														//Taking user input

		if (cin.fail() == true)													//Testing for non-integer entry
		{
			cin.clear();
			cin.ignore();
			user_number = 0;
			clockmenu();
		}

		if ((user_number <= 0) || (user_number >= 5))                           //Testing for non-menu item entry
		{
			clockmenu();
		}


		switch (user_number)													//Switches for menu manipulation
		{
		case 1:																	//Adds one hour
			TWENTYTIME_HOURS++;
			TWELVETIME_HOURS++;
			break;
		case 2:																	//Adds one minute
			TWENTYTIME_MINUTES++;
			TWELVETIME_MINUTES++;
			break;
		case 3:																	//Adds one second
			TWENTYTIME_SECONDS++;
			TWELVETIME_SECONDS++;
			break;
		case 4:
			exit(1);
			break;
		}


	}

	//return;
}


//Main function, only for calling the clock display and using buttons.
int main()
{
	while (true)
	{
		thread t1(clockdisplay);
		thread t2(clockcode);
		thread t3(clockmenu);

		t1.join();
		t2.join();
		t3.join();

		return(0);

	}
}
