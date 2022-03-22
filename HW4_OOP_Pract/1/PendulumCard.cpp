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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard(std::string PendulumName, std::string PendulumEffect, unsigned int AttackP, unsigned int DefenseP, Type PendType, unsigned int Scale,unsigned Rarity)
	:Card(PendulumName,PendulumEffect,Rarity),MagicCard(PendulumName, PendulumEffect,PendType,Rarity),MonsterCard(PendulumName,PendulumEffect,AttackP, DefenseP,Rarity)
{
	this->PendulumScale = 0;
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

void PendulumCard::printf() const
{
	std::cout << "This Card is a MagicCard type ";
	switch (this->CardType)
	{
	case Type::buff:
		std::cout << "Buff";
		break;
	case Type::spell:
		std::cout << "Spell";
		break;
	case Type::trap:
		std::cout << "Trap";
		break;
	case Type::None:
		std::cout << "DEFAULT(NONE/NOT SET)";
		break;
	}
	std::cout << "\n This MagicCards name is " << this->Name << " it's effect is " << this->Effect << " it's rarity is " << " attack is " << this->Attack_P << " it's defense is " << this->Defense_P << " it's rarity is " << this->Rarity << "\n";
}
