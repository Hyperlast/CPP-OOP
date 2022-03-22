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
#include "Base.hpp"
enum class Type
{
	None,
	trap,
	buff,
	spell,
};
class MagicCard : virtual public BaseCard
{
private:
	Type CardType;
public:
	MagicCard(std::string= " ", std::string = " ", Type Type=Type::None);
	Type getType()const;
};