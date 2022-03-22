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
#include "Armor.hpp"
int Armor::calcGearScore(std::vector<std::pair<std::string, unsigned int>> Te)
{
	int Temp = 0;
	for (unsigned int i = 0; i < Te.size(); ++i)
	{
		Temp += Te[i].second;
	}
	return Temp;
}
double Armor::getScore()
{
	return this->Gearscore;
}
int Armor::getSlots()
{
	return this->Slots;
}
void Armor::Printf()const
{
	switch (this->AType)
	{
	case ArmorType::cloth:
		std::cout << "Cloth ";
		break;
	case ArmorType::leather:
		std::cout << "Leather ";
		break;
	case ArmorType::mail:
		std::cout << "Mail ";
		break;
	}
	std::cout << "Armor with defense " << this->defense<<std::endl;
	for (unsigned int i = 0; i < this->ArmorEffect.size(); ++i)
	{
		std::cout << "Effect number: " << i << " : " << ArmorEffect[i].first << "with power " << ArmorEffect[i].second<<std::endl;
	}
	std::cout << "Armor GearScore " << this->Gearscore;
}
Armor& Armor::operator=(const Armor& CopyArmor)
{
	if (this != &CopyArmor)
	{
		this->defense = CopyArmor.defense;
		this->AType = CopyArmor.AType;
		for (unsigned int i = 0; i < CopyArmor.ArmorEffect.size(); ++i)
		{
			std::pair<std::string, unsigned int> Temp;
			Temp.first = CopyArmor.ArmorEffect[i].first;
			Temp.second = CopyArmor.ArmorEffect[i].second;
			this->ArmorEffect.push_back(Temp);
		}
		this->Gearscore = CopyArmor.Gearscore;
	}
	return *this;
}
bool Armor::operator==(const Armor& Temp)
{
	if (this->AType != Temp.AType)
		return 0;
	if (this->defense != Temp.defense)
		return 0;
	if (this->Gearscore != Temp.Gearscore)
		return 0;
	if (this->ArmorEffect.size() != Temp.ArmorEffect.size())
		return 0;
	for (unsigned int i = 0; i < ArmorEffect.size(); ++i)
	{
		if (this->ArmorEffect[i] != Temp.ArmorEffect[i])
			return 0;
	}
	return 1;
}
Armor::Armor()
{
	this->defense = 0;
	this->AType = ArmorType::cloth;
	std::pair<std::string,unsigned int> Temp;
	Temp.first = "\0";
	Temp.second = 0;
	this->ArmorEffect.push_back(Temp);
	this->Gearscore = 0;
}

Armor::Armor(ArmorType AR, int Def, std::vector<std::pair<std::string, unsigned int>> TAKE)
{
	this->defense = Def;
	this->AType = AR;
	for (unsigned int i = 0; i < TAKE.size(); ++i)
	{
		std::pair<std::string, unsigned int> Temp;
		Temp.first = TAKE[i].first;
		Temp.second = TAKE[i].second;
		this->ArmorEffect.push_back(Temp);
	}
	this->Gearscore = calcGearScore(TAKE);
}


Armor::Armor(const Armor& CopyArmor)
{
	this->defense = CopyArmor.defense;
	this->AType = CopyArmor.AType;
	for (unsigned int i = 0; i < CopyArmor.ArmorEffect.size(); ++i)
	{
		std::pair<std::string, unsigned int> Temp;
		Temp.first = CopyArmor.ArmorEffect[i].first;
		Temp.second = CopyArmor.ArmorEffect[i].second;
		this->ArmorEffect.push_back(Temp);
	}
	this->Gearscore = CopyArmor.Gearscore;
}

void Armor::addArmorEffect(std::string addName, unsigned int addPow)
{
	std::pair<std::string, unsigned int> Temp;
	Temp.first = addName;
	Temp.second = addPow;
	ArmorEffect.push_back(Temp);
	this->Gearscore = calcGearScore(this->ArmorEffect);
}

void Armor::deleteArmorEffect(std::string Deleter)
{
	for (unsigned int i = 0; i < this->ArmorEffect.size(); ++i)
	{
		if (ArmorEffect[i].first == Deleter)
		{
			ArmorEffect.erase(ArmorEffect.begin() + i);
		}
	}
	this->Gearscore = calcGearScore(this->ArmorEffect);
}

void Armor::changeArmorEffectPow(std::string Name, unsigned int ChangePow)
{
	for (unsigned int i = 0; i < this->ArmorEffect.size(); ++i)
	{
		if (ArmorEffect[i].first == Name)
		{
			ArmorEffect[i].second = ChangePow;
		}
	}
	this->Gearscore = calcGearScore(this->ArmorEffect);
}

void Armor::changeDefensePoints(unsigned int def)
{
	this->defense = def;
}

void Armor::changeArmorType(ArmorType T)
{
	this->AType = T;
}

std::ostream& operator<<(std::ostream& out, const Armor& in)
{
	std::string TypeOfA;
	switch (in.AType)
	{
	case ArmorType::cloth:
		TypeOfA = "cloth";
		break;
	case ArmorType::leather:
		TypeOfA = "leather";
		break;
	case ArmorType::mail:
		TypeOfA = "mail";
		break;
	}
	out << TypeOfA << " ";
	out << " with defense " << in.defense;
	for (unsigned int i = 0; i < in.ArmorEffect.size(); ++i)
	{
		out << in.ArmorEffect[i].first << " " << in.ArmorEffect[i].second << "\n";
	}
	return out;
}
