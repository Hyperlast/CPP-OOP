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
#include "Dates.hpp"
#include <iostream>

int CheckMaxDays(int m, int y)
{
	int MaxDays = 0;
	bool IsYLeap = false;

	if (y % 4 == 0 || y % 100 == 0)
	{
		IsYLeap = true;
	}

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		 MaxDays = 31;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		MaxDays = 30;
	}
	if (m == 2)
	{
		if (IsYLeap)
		{
			MaxDays = 29;
		}
		else
		{
			MaxDays = 28;
		}
	}

	return MaxDays;
}

Date::Date()
{
	dd = 1;
	mm = 1;
	yy = 2000;
}

Date::Date(int d, int m, int y)
{
	
	if (m < 1 || m>12)
	{
		m = 1;
	}
	int MaxD = CheckMaxDays(m,y) ;
	if (d > MaxD || d < 1)
	{
		d = 1;
	}
	
	this->dd = d;
	this->mm = m;
	this->yy = y;
	
	
}

void Date::addDays(int d)
{	
	
	while (d > 0)
	{
		if ((this->dd + d) > CheckMaxDays(this->mm,this->yy))
		{
			d -= ((CheckMaxDays(this->mm, this->yy) - this->dd) + 1);
			this->dd = 1;
			if (this->mm < 12)
			{
				this->mm++;
			}
			else {
				this->mm = 1;
				this->yy++;
			}
		}
		else
		{
			this->dd += d;
			d = 0;
		}
	}
	
}

void Date::removeDays(int d)
{
	while (d > 0)
	{
		if ((this->dd - d) < 1)
		{
			d -= (this->dd + 1);
			if (this->mm == 1)
			{
				this->mm = 12;
				this->yy--;
			}
			else
			{
				this->mm--;
			}
			this->dd = CheckMaxDays(this->mm, this->yy);
			
		}
		else
		{	
			this->dd -= d;
			d = 0;
		}
	}
}

bool Date::isLeapYear() const
{
	if(this->yy % 4 == 0 || this->yy % 100 == 0) return true;

	return false;
}

int Date::DaysToXmas() const
{
	int d = 25;
	int m = 12;
	int y = this->yy;
	if (d < this->dd && m == this->mm) y++;
	int DaysCounter=0;
	while (this->dd != d || this->mm != m || this->yy != y)
	{
		if (d == 1)
		{
			d = CheckMaxDays(m, y);
			if (m == 1)
			{
				m = 12;
				y--;
				DaysCounter++;
			}
			else
			{
				m--;
			}
		}
		else {
			d--;
		}
		DaysCounter++;
	}
	DaysCounter--;
	return DaysCounter--;
}

int Date::DaysToNYE() const
{
	int d = 31;
	int m = 12;
	int DaysCounter = 1;
	while (this->dd != d || this->mm != m)
	{
		if (d == 1)
		{
			m--;
			d = CheckMaxDays(m, this->yy);
			std::cout << "This is d: " << d << std::endl;
		}
		else {
			
			d--;
		}
		DaysCounter++;
	}
	return DaysCounter++;

	
}

int Date::DaysToEvent(const Date& Rand)
{
	int D = Rand.dd;
	int M = Rand.mm;
	int Y = Rand.yy;
	int DaysCounter = 0;
	while (this->dd != D || this->mm != M||this->yy!=Y)
	{
		if (D == 1)
		{
			D = CheckMaxDays(M, Y);
			
			if (M == 1)
			{
				M = 12;
				Y--;
				DaysCounter++;
			}
			else 
			{
				M--;
			}
		}
		else {
			D--;
		}
		DaysCounter++;
	}
	return DaysCounter--;
}

bool Date::isLaterThen(const Date& Rand)
{
	if (this->yy > Rand.yy) return false;
	if (this->yy < Rand.yy) return true;

	if(this->mm > Rand.mm) return false;
	else
	{
		if (this->mm < Rand.mm)
		{
			return true;
		}
		if (this->mm == Rand.mm)
		{
			return this->dd < Rand.dd;
		}
	}
	return true;
}

void Date::print_f() const
{
	std::cout << this->dd << "." << this->mm << "." << this->yy << std::endl;
}

