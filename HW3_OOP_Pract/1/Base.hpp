/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 3
* @compiler VC
*/
#pragma once
#include<string>
#include<iostream>
class BaseCard
{
private:
	std::string Name;
	std::string Effect;

public:
	BaseCard(std::string B_Name= " ", std::string B_Effect = " ")
	{
		this->Name = B_Name;
		this->Effect = B_Effect;
	}
	std::string getName()const
	{
		return this->Name;
	}
	std::string getEffect()const
	{
		return this->Effect;
	}
};