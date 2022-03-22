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
enum class Type
{
	None,
	trap,
	buff,
	spell,
};
class MagicCard : virtual public Card
{
protected:
	Type CardType;
public:
	MagicCard(std::string= " ", std::string = " ", Type Type=Type::None,unsigned Rarity=0);
	Type getType()const;
	void printf()const;

};