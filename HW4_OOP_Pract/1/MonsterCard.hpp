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
#include "Card.hpp"

class MonsterCard : virtual public Card
{
protected:
	unsigned int Attack_P;
	unsigned int Defense_P;
public:
	MonsterCard(std::string MonsterName = " ", std::string MonsterEffect = " ", unsigned int Attack = 0, unsigned int Defense = 0,unsigned Rarity = 0);
	unsigned int getAttack()const;
	unsigned int getDefense()const;

	void printf()const;

};