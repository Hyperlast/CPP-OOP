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
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
class PendulumCard : public MonsterCard, public MagicCard
{
private:
	unsigned int PendulumScale;
public:
	PendulumCard(std::string PendulumName = " ", std::string PendulumEffect = " ", unsigned int AttackP = 0, unsigned int DefenseP = 0 , Type Type = Type::None, unsigned int Scale = 1,unsigned Rarity = 0);
	unsigned int getScale()const;

	void printf()const;

};