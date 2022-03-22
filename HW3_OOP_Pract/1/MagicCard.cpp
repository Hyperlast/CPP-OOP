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
#include "MagicCard.hpp"

MagicCard::MagicCard(std::string MagicName , std::string MagicEffect , Type Type)
	: BaseCard(MagicName,MagicEffect)
{
	this->CardType = Type;
}

Type MagicCard::getType()const
{
	return this->CardType;
}
