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
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Weapons.hpp"
#include "Money.hpp"
#include "Inventory.hpp"
int main()
{
	
	std::pair<unsigned int, std::string> TempGold;
	TempGold.first = 3;
	TempGold.second = "gold";
	std::pair<unsigned int, std::string> TempSilv;
	TempSilv.first = 3;
	TempSilv.second = "silver";
	std::vector<std::pair<unsigned int, std::string>> Moneyd;
	Moneyd.push_back(TempGold);
	Moneyd.push_back(TempSilv);
	Money M(Moneyd);
	M.Printf();
	/*M.addMoney(505, "silver");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	M.Printf();
	M.deleteMoney();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	M.Printf();
	M.takeMoney(0, "gold");
	M.takeMoney(204, "silver");
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	M.Printf();

	Money P(Moneyd);
	M = P;

	M.Printf();*/
	
	//Materials
	//
	//
	//
	//Materials S;
	//std::vector<std::pair<materials, unsigned int>> mats;
	//std::pair<materials, unsigned int> Temp;
	//Temp.first = materials::herbs;
	//Temp.second = 14;
	//mats.push_back(Temp);
	//Temp.first = materials::ores;
	//Temp.second = 10;
	//mats.push_back(Temp);
	//Temp.first = materials::cloth;
	//Temp.second = 10;
	//mats.push_back(Temp);
	//Temp.first = materials::essence;
	//Temp.second = 10;
	//mats.push_back(Temp);
	//Materials Q(mats);
	

	////Equipment
	////
	////
	////
	//std::vector<Weapon> Weap;
	//std::pair<unsigned int, unsigned int> HitDmg;
	//HitDmg.first = 10;
	//HitDmg.second = 20;
	//std::vector<std::pair<std::string, unsigned int>> Effects;
	//std::pair<std::string, unsigned int> Effect1;
	//Effect1.first = "Sharpness IV";
	//Effect1.second = 13;
	//std::pair<std::string, unsigned int> Effect2;
	//Effect2.first = "Fire Aspect II";
	//Effect2.second = 6;
	//Effects.push_back(Effect1);
	//Effects.push_back(Effect2);

	//Weapon Temp(Type::OneHanded, WeaponTypeName::dagger, HitDmg, Effects);
	//std::vector<Weapon> TempWeapons;
	//TempWeapons.push_back(Temp);
	//TempWeapons.push_back(Temp);
	//TempWeapons.push_back(Temp);
	//TempWeapons.push_back(Temp);

	//Equipment<Weapon> E(TempWeapons);
	//std::cout << E.isFull();
	//std::cout << E.isEmpty();
	//std::cout << std::endl;
	//std::cout << std::endl;
	//std::cout << std::endl;
	//Equipment<Weapon> Copy(E);
	//std::cout << Copy.SlotsTaken();
	//Copy.RemoveEquipment();
	//std::cout << std::endl;
	//std::cout << Copy.SlotsTaken();
	//

	Backpack<Money> E(M);
	std::cout << M;
	std::cout << E;
	Inventory<Backpack<Money>> P;
	Inventory<Backpack<Money>> T;
	if (P == T)
	{
		std::cout << " Works";
	}
	if (P != T)
	{
		std::cout << " Doesn't work ";
	}
	Inventory<Backpack<Money>> Dif(E);
	if(Dif==T)
	{
		std::cout << " Works ";
	}
	if (Dif != T)
	{
		std::cout << " Doesn't work ";
	}
	std::cout<< P;


	return 0;
}