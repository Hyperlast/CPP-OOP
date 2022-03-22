/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Kalin Borisov
* @idnumber 62580
* @task 1
* @compiler - VC
*/
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
class Money 
{
private:
	std::vector<std::pair<unsigned int, std::string>> Balance;
public:
	Money();
	Money(std::vector<std::pair<unsigned int, std::string>>);
	Money(const Money&);
	~Money()=default;

	void addMoney(unsigned int,std::string);
	void takeMoney(unsigned int,std::string);
	void deleteMoney();
	void Printf()const;
	int getSlots();

	Money& operator +=(const Money&);
	Money& operator -=(const Money&);
	friend std::ostream& operator<<(std::ostream& out, const Money& in);
};