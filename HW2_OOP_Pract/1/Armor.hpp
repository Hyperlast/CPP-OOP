/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Kalin Borisov
* @idnumber 62580
* @task 1
* @compiler - VC
*/
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
enum class ArmorType
{
	cloth,
	leather,
	mail,
};

class Armor
{
private:
	ArmorType AType;
	unsigned int defense;
	std::vector<std::pair<std::string, unsigned int>> ArmorEffect;
	int Gearscore;
	const unsigned int Slots = 1;
public:
	//the big 4s
	Armor();
	Armor(ArmorType, int, std::vector<std::pair<std::string, unsigned int>>);
	Armor(const Armor&);
	~Armor() = default;
	//methods
	void addArmorEffect(std::string, unsigned int);
	void deleteArmorEffect(std::string);
	void changeArmorEffectPow(std::string, unsigned int);
	void changeDefensePoints(unsigned int);
	void changeArmorType(ArmorType);
	int calcGearScore(std::vector<std::pair<std::string, unsigned int>>);

	double getScore();
	int getSlots();
	void Printf()const;

	Armor& operator = (const Armor&);
	bool operator ==(const Armor&);
	friend std::ostream& operator<<(std::ostream& out, const Armor& in);
};

