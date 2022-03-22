/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 1
* @compiler VC
*/
#pragma once

class Date
{
private:
	int dd;
	int mm;
	int yy;
public:
	//constructors
	Date();
	Date(int, int, int);
	//methods
	void addDays(int);
	void removeDays(int);
	bool isLeapYear()const;
	int DaysToXmas()const;
	int DaysToNYE()const;
	int DaysToEvent(const Date&);
	bool isLaterThen(const Date&);
	void print_f()const;

};