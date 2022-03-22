/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 4
* @compiler VC
*/
#pragma once
#include<string>
#include<iostream>
class Card
{
protected:
	std::string Name;
	std::string Effect;
	unsigned Rarity;

public:
	Card(std::string B_Name = " ", std::string B_Effect = " ", unsigned B_Rarity = 0);

	std::string getName()const;
	
	std::string getEffect()const;

	unsigned getRarity()const;
	
	bool operator>(const Card& RHS)const;
	bool operator<(const Card& RHS)const;
	
	virtual void printf()const = 0;
	
};