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
#include<iostream>
#include <string>
#include <utility>
#include <vector>
enum class Type
{
	OneHanded,
	TwoHanded,
	Default,
};
enum class WeaponTypeName
{
	axe,
	sword,
	dagger,
	mace,
	staff,
	Default,
};

class Weapon
{
private:
	WeaponTypeName WeaponClass;
	Type WeaponType;
	std::pair<unsigned int,unsigned int> HitDamage;
	std::vector<std::pair<std::string,unsigned int>> Effect;
	double WeaponScore;
	unsigned int Slots;

public:
	//the big 4s
	Weapon();
	Weapon(Type , WeaponTypeName , std::pair<unsigned int, unsigned int>, std::vector<std::pair<std::string, unsigned int>>);
	Weapon(const Weapon&);
	~Weapon()=default;
	//methods
	void addWeaponEffect(std::string, unsigned int);
	void deleteWeaponEffect(std::string);
	void changePowerOfEffect(std::string, unsigned int);
 
	int getWeaponType();
	double getScore();
	int getSlots();

	void ChangeWeaponClass(WeaponTypeName); 
	void ChangeWeaponType(Type);
	void Printf()const;

	Weapon& operator =(const Weapon& );
	bool operator ==(const Weapon&);
	friend std::ostream& operator<<(std::ostream& out, const Weapon& in);
	double WeaponScoreCalc(Type, std::pair<unsigned int, unsigned int>& ScoreHitDamage, std::vector<std::pair<std::string, unsigned int>>& ScoreEffects);
};

