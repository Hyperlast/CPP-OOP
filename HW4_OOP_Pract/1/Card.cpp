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
#include "Card.hpp"

Card::Card(std::string B_Name, std::string B_Effect, unsigned B_Rarity)
{
    this->Name = B_Name;
    this->Effect = B_Effect;
    this->Rarity = B_Rarity;
}

std::string Card::getName() const
{
    return this->Name;
}

std::string Card::getEffect() const
{
    return this->Effect;
}

unsigned Card::getRarity() const
{
	return this->Rarity;
}

bool Card::operator>(const Card& RHS) const
{
    if (this->Rarity > RHS.getRarity())
    {
        return true;
    }
    return false;
}

bool Card::operator<(const Card& RHS) const
{
    if (this->Rarity < RHS.getRarity())
    {
        return true;
    }
    return false;
}


