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
#include "MagicCard.hpp"

MagicCard::MagicCard(std::string MagicName, std::string MagicEffect, Type Type, unsigned Rarity)
	: Card(MagicName, MagicEffect, Rarity), CardType(Type)
{
}

Type MagicCard::getType()const
{
	return this->CardType;
}

void MagicCard::printf() const
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
	std::cout << "\nThis MagicCards name is " << this->Name << " it's effect is " << this->Effect<<" it's rarity is "<<this->Rarity<<"\n";
}


