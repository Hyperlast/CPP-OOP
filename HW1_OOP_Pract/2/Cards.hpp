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
unsigned int my_strlen(const char*);
char* copyString(const char*);
class MonsterCard
{
private:
	char* MonsterName;
	unsigned int AttackPoints;
	unsigned int DefensePoints;

public:
	//setters
	void setMonsterName(const char*);
	void setAttackPoints(const unsigned int);
	void setDefensePoints(const unsigned int);
	//getters
	const char* getMonsterName()const;
	const int getAttackPoints()const;
	const int getDefensePoints()const;
	//methods
	MonsterCard();
	MonsterCard(const char*, unsigned int, unsigned int);
	//destructor
	~MonsterCard()=default;
};

class MagicCard
{
private:
	char* MagicName;
	char* Effect;
	char* Type;
	bool IsTypeRight(const char*);
public:
	//setters
	void setMagicName(const char*);
	void setEffect(const char*);
	void setType(const char*);
	//getters 
	const char* getMagicName()const;
	const char* getEffect()const;
	const char* getType()const;
	//methods
	MagicCard();
	MagicCard(const char*, const char*, const char*);
	//destructors
	~MagicCard()=default;
};