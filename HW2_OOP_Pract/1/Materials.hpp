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
enum class materials
{
	herbs, 
	ores, 
	cloth, 
	essence,
	Default,
};

class Materials
{
private:
	std::vector<std::pair<materials, unsigned int>> mats;
	unsigned int Slots;
public:
	Materials();
	Materials(std::vector<std::pair<materials, unsigned int>>);
	Materials(const Materials&);
	~Materials()=default;

	void addMats(materials, unsigned int);
	void TakeMats(materials, unsigned int);
	void RemoveMats();
	void Printf()const;
	int getSlots();

	Materials& operator =(const Materials&);
	Materials& operator +=(const Materials&);
	Materials& operator -=(const Materials&);


	int CalcSlots(std::vector<std::pair<materials, unsigned int>>);
	friend std::ostream& operator<<(std::ostream& out, const Materials& in);
};