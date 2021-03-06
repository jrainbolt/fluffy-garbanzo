// ClassDayOfYearExercise11.3.2018.cpp : Defines the entry point for the console application.
//Program to demonstrate the class DayOfYear

#include "stdafx.h"
#include <iostream>
using namespace std;

class DayOfYear {
public:
	void input();
	void output();

	void set(int new_month, int new_day);
	//Precondition: new_month and new_day form a possible date.
	//Postcondition: The date is reset according to the arguments.

	int get_month();
	//returns the month, 1 for January, 2 for February, etc.

	int get_day();
	//Returns the day of the month.
private:
	void check_date(); // <---Private member function
	int month;
	int day;

};

int main()
{
	DayOfYear today, bach_birthday;
	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output;

	bach_birthday.set(3, 21);
	cout << "J. S. Bach's Birthday is ";
	bach_birthday.output();

	if (today.get_month() == bach_birthday.get_month() && today.get_day() == bach_birthday.get_day())
		cout << "Happy Birthday Johann Sebastion!\n";
	else
		cout << "Happy Unbirthday Johann Sebastion!\n";
    return 0;
}
//Uses iostream:
void DayOfYear::input() {
	cout << "Enter the month as a number: ";    
	cin >> month;                                //<----Private members may be used in member function definitions(but not elsewhere)
	cout << "Enter the day of the month: ";
	cin >> day;                                 //<----
	check_date();                               //<----
}

void DayOfYear::output() {
	cout << "month = " << month << ", day = " << day << endl; // <--Member function definition
}

void DayOfYear::set(int new_month, int new_day) {
	month = new_month;
	day = new_day;
	check_date(); // The member function check_date does not check for all illegal dates, but it would be asy to make the check complete by making it longer.
}

void DayOfYear::check_date() {
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cout << "Illegal date. Aborting program.\n";
		exit(1); //The function exit is discussed in chapter 6. It ends the program.
	}
}
int DayOfYear::get_month() {
	return month;
}
int DayOfYear::get_day() {
	return day;
}