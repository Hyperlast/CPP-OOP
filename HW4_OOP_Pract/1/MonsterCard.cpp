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
#include "MonsterCard.hpp"

MonsterCard::MonsterCard(std::string MonsterName, std::string MonsterEffect, unsigned int Attack, unsigned int Defense,unsigned Rarity)
    : Card(MonsterName, MonsterEffect,Rarity),Attack_P(Attack),Defense_P(Defense)
{
}

unsigned int MonsterCard::getAttack()const
{
    return this->Attack_P;
}

unsigned int MonsterCard::getDefense()const
{
    return this->Defense_P;
}

void MonsterCard::printf() const
{
    std::cout <<"This card is a MonsterCard. It's name is "<<this->Name<<" it's effect is "<<this->Effect<<"\nThis cards"<<
        " attack is "<<this->Attack_P<<" it's defense is "<<this->Defense_P<< " it's rarity is " << this->Rarity << "\n";
}

