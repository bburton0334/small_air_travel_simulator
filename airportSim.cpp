/*
* FILE : ca3.cpp
* PROJECT : SENG1000 - Assignment 3
* PROGRAMMER : Briana Burton
* FIRST VERSION : 2020-03-15
* DESCRIPTION :
* The functions in this file are used to calculate the traveling 
* time between locations that are input by the user.
*/
#include <stdio.h>
#include <iostream>
using namespace std;



enum values
{
	MAX_CITY = 7,
	MIN_CITY = 0,
	MINUTE_HOUR = 60
};



int getNum(void);
int calculateTime(int homeCity, int destinationCity);



int main(void)
{
	int homeCity = 0;
	int destinationCity = 0;

	while (true)
	{
		cout << "Home City   " "  Destination City  " "  Flying Time  " "  Layover Time\n"
				"---------   " "  ----------------  " "  -----------  " "  ------------\n"
				"(1)Toronto  " "  (2)Atlanta        " "  4:15         " "  1:20\n"
				"(2)Atlanta  " "  (3)Austin         " "  3:58         " "  0:46\n"
				"(3)Austin   " "  (4)Denver         " "  3:55         " "  11:29\n"
				"(4)Denver   " "  (5)Chicago        " "  2:14         " "  0:53\n"
				"(5)Chicago  " "  (6)Buffalo        " "  3:27         " "  none\n";

		cout << "\n\nEnter home city number (enter 0 to quit): ";
		homeCity = getNum();

		if (homeCity == 0)
		{
			break;
		}
		else
		{
			cout << "Enter destination city number: ";
			destinationCity = getNum();

			if ((homeCity < MAX_CITY) && (homeCity > MIN_CITY))
			{
				calculateTime(homeCity, destinationCity);
			}
			else
			{
				cout << "\n Error: invalid input\n\n";
			}
		}
	}

	return 0;
}



/*
* FUNCTION		: calculateTime()
* DESCRIPTION	:
*	This function calculates the traveling time between
*	locations and ouputs the total traveling time or error
* PARAMETERS	:
*	int homeCity : number of the home city that was input
*	by the user
*	int destinationCity : number of the destination city
*	that was input by the user
* RETURNS		:
*	none
*/
int calculateTime(int homeCity, int destinationCity)
{
	const int kFlyingTimeHours[6] = { 4, 3, 3, 2, 3 };
	const int kFlyingTimeMinutes[6] = { 15, 58, 55, 14, 27 };
	const int kLayoverTimeHours[6] = { 1, 0, 11, 0, 0 };
	const int kLayoverTimeMinutes[6] = { 20, 46, 29, 53, 0 };

	if ((homeCity != destinationCity) && (homeCity < destinationCity) && (destinationCity < MAX_CITY))
	{
		if (destinationCity == homeCity + 1)
		{
			int totalHours = kFlyingTimeHours[homeCity - 1];
			int totalMinutes = kFlyingTimeMinutes[homeCity - 1];

			cout << "\n Total traveling time including any layover(s) is " << totalHours << ":" << totalMinutes << "\n\n";

			return 0;
		}
		else
		{
			int flyingTimeHoursSum = 0, flyingTimeMinutesSum = 0;
			int layoverTimeHoursSum = 0, layoverTimeMinutesSum = 0;

			for (int i = homeCity; i < destinationCity; i++)
			{
				flyingTimeHoursSum += kFlyingTimeHours[i - 1];
				flyingTimeMinutesSum += kFlyingTimeMinutes[i - 1];
			}
			for (int i = homeCity; i < destinationCity - 1; i++)
			{
				layoverTimeHoursSum += kLayoverTimeHours[i - 1];
				layoverTimeMinutesSum += kLayoverTimeMinutes[i - 1];
			}

			int totalMinutes = flyingTimeMinutesSum + layoverTimeMinutesSum;
			int totalHours = flyingTimeHoursSum + layoverTimeHoursSum + (totalMinutes / MINUTE_HOUR);
			totalMinutes = totalMinutes % MINUTE_HOUR;

			cout << "\n Total traveling time including any layover(s) is " << totalHours << ":" << totalMinutes << "\n\n";

			return 0;
		}
	}
	else if (homeCity == destinationCity)
	{
		cout << "\n Error: home city cannot be the same as destination city\n\n";
	}
	else if (homeCity > destinationCity)
	{
		cout << "\n Error: Cannot travel backwards\n\n";
	}
	else
	{
		cout << "\n Error: invalid input\n\n";
	}

	return 0;
}



/*
* FUNCTION		: getNum()
* DESCRIPTION	:
*	This function takes input from the user and returns
*	it to the integer
* PARAMETERS	:
*	none
* RETURNS		:
*	number : the number that was input by the user
*/
#pragma warning(disable: 4996)
int getNum(void)
{
	char record[121] = { 0 };
	int number = 0;

	fgets(record, 121, stdin);
	if (sscanf(record, "%d", &number) != 1)
	{
		number = -1;
	}
	return number;
}