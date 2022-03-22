/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 2
* @compiler VC
*/

#pragma once
#include "Cards.hpp"

class Deck {
private:
	//20 MOnsters and 20 Magic max
	MonsterCard Monsters[20];
	MagicCard Magic[20];
	
public:
	//methods
	int getMagicCardCount();
	int getMonsterCardCount();
	void ChangeMonsterCard(unsigned int,const char*,unsigned int,unsigned int);
	void ChangeMagicCard(unsigned int, const char*, const char*, const char*);
	void ReplaceMonsterCard(unsigned int, MonsterCard&);
	void ReplaceMagicCard(unsigned int, MagicCard&);
	
};
class Duelist
{
private:
	char* Name;
	Deck DuelistDeck;
public:
	void DuelistChangeMonsterCard(unsigned int, const char*, unsigned int, unsigned int);
	void DuelistChangeMagicCard(unsigned int, const char*, const char*, const char*);
	void DuelistReplaceMonsterCard(unsigned int, MonsterCard&);
	void DuelistReplaceMagicCard(unsigned int, MagicCard&);
};