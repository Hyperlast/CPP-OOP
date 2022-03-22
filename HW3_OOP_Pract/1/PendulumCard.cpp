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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard(std::string PendulumName, std::string PendulumEffect, unsigned int AttackP, unsigned int DefenseP, Type PendType, unsigned int Scale)
	:BaseCard(PendulumName,PendulumEffect),MagicCard(PendulumName, PendulumEffect,PendType),MonsterCard(PendulumName,PendulumEffect,AttackP, DefenseP)
{
	if (Scale > 13)
	{
		this->PendulumScale = 13;
	}
	if (Scale < 1)
	{
		this->PendulumScale = 1;
	}
	if (Scale > 1 && Scale < 13)
	{
		this->PendulumScale = Scale;
	}
}

unsigned int PendulumCard::getScale()const
{
	return this->PendulumScale;
}
