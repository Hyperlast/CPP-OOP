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
#include "MonsterCard.hpp"

MonsterCard::MonsterCard(std::string MonsterName, std::string MonsterEffect, unsigned int Attack, unsigned int Defense)
    : BaseCard(MonsterName, MonsterEffect)
{
    this->Attack_P = Attack;
    this->Defense_P = Defense;
}

unsigned int MonsterCard::getAttack()const
{
    return this->Attack_P;
}

unsigned int MonsterCard::getDefense()const
{
    return this->Defense_P;
}
