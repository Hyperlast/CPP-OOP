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
#include "Materials.hpp"

Materials::Materials()
{
	std::pair<materials, unsigned int> Herb;
	Herb.first = materials::herbs;
	Herb.second = 0;
	std::pair<materials, unsigned int> Ores;
	Ores.first = materials::ores;
	Ores.second = 0;
	std::pair<materials, unsigned int> Cloth;
	Cloth.first = materials::cloth;
	Cloth.second = 0;
	std::pair<materials, unsigned int> Essence;
	Essence.first = materials::essence;
	Essence.second = 0;
	mats.push_back(Herb);
	mats.push_back(Ores);
	mats.push_back(Cloth);
	mats.push_back(Essence);
	
	this->Slots = 0;
}

Materials::Materials(std::vector<std::pair<materials, unsigned int>> R)
{
	for (unsigned int i = 0; i < R.size(); ++i)
	{
		std::pair<materials, unsigned int> Temp;
		Temp.first = R[i].first;
		Temp.second = R[i].second;
		this->mats.push_back(Temp);
		if (CalcSlots(this->mats) > 16)
		{
			mats.pop_back();
		}
	}
	this->Slots=CalcSlots(this->mats);

}

Materials::Materials(const Materials& CopyMat)
{
	for (unsigned int i = 0; i < CopyMat.mats.size(); ++i)
	{
		std::pair<materials, unsigned int> Temp;
		Temp.first = CopyMat.mats[i].first;
		Temp.second = CopyMat.mats[i].second;
		this->mats.push_back(Temp);
	}
	this->Slots = CopyMat.Slots;
}

void Materials::addMats(materials T, unsigned int ADD)
{
	switch (T)
	{
	case materials::herbs:
		mats[0].second += ADD;
		if (CalcSlots(this->mats) > 16)
		{
			mats[0].second -= ADD;
		}
		break;
	case materials::ores:
		mats[1].second += ADD;
		if (CalcSlots(this->mats) > 16)
		{
			mats[1].second -= ADD;
		}
		break;
	case materials::cloth:
		mats[2].second += ADD;
		if (CalcSlots(this->mats) > 16)
		{
			mats[2].second -= ADD;
		}
		break;
	case materials::essence:
		mats[3].second += ADD;
		if (CalcSlots(this->mats) > 16)
		{
			mats[3].second -= ADD;
		}
		break;
	}
	this->Slots = CalcSlots(this->mats);
}

void Materials::TakeMats(materials Tem, unsigned int REMOVE)
{
	switch (Tem)
	{
	case materials::herbs:
		if (mats[0].second >= REMOVE)
		{
			mats[0].second -= REMOVE;
		}
		break;
	case materials::ores:
		if (mats[1].second >= REMOVE)
		{
			mats[1].second -= REMOVE;
		}
		break;
	case materials::cloth:
		if (mats[2].second >= REMOVE)
		{
			mats[2].second -= REMOVE;
		}
		break;
	case materials::essence:
		if (mats[3].second >= REMOVE)
		{
			mats[3].second -= REMOVE;
		}
		break;
	}
	this->Slots = CalcSlots(this->mats);
}

void Materials::RemoveMats()
{
	mats[0].second = 0;
	mats[1].second = 0;
	mats[2].second = 0;
	mats[3].second = 0;
	this->Slots = 0;
}

void Materials::Printf()const
{
	std::vector<std::string> Mater = {"herbs","ores","cloth","essence"};
	for (unsigned int i=0; i < Mater.size(); ++i)
	{
		std::cout << "Material type: " << Mater[i] << " Amount " << mats[i].second;
	}
}

int Materials::getSlots()
{
	return this->Slots;
}

Materials& Materials::operator=(const Materials& Same)
{
	if (this != &Same)
	{
		this->mats = Same.mats;
		this->Slots = Same.Slots;
	}
	return *this;
}

Materials& Materials::operator+=(const Materials& ADD)
{
	if (this != &ADD)
	{
		for (unsigned int i = 0; i < ADD.mats.size(); ++i)
		{
			this->mats[i].second += ADD.mats[i].second;
			if (CalcSlots(this->mats) > 16)
			{
				this->mats[i].second -= ADD.mats[i].second;
			}
		}
	}
	return *this;
}

Materials& Materials::operator-=(const Materials& SUB)
{
	if (this != &SUB)
	{
		for (unsigned int i = 0; i < SUB.mats.size(); ++i)
		{
			if ((this->mats[i].second - SUB.mats[i].second) >= 0)
			{
				this->mats[i].second -= SUB.mats[i].second;
			}
		}
	}
	return *this;
}

int Materials::CalcSlots(std::vector<std::pair<materials, unsigned int>> CalcMats)
{
	int SlotsGeneralTemp = 0;
	int MaterialSlots = 0;

	MaterialSlots = CalcMats[0].second;
	SlotsGeneralTemp += (MaterialSlots /20);
	MaterialSlots = CalcMats[1].second;
	SlotsGeneralTemp += (MaterialSlots / 20);
	MaterialSlots = CalcMats[2].second;
	SlotsGeneralTemp += (MaterialSlots / 20);
	MaterialSlots = CalcMats[3].second;
	SlotsGeneralTemp += (MaterialSlots / 10);

	return SlotsGeneralTemp;
}

std::ostream& operator<<(std::ostream& out, const Materials& in)
{
	for (unsigned int i = 0; i < in.mats.size(); ++i)
	{
		std::string nameOfMat;
		switch (in.mats[i].first)
		{
		case materials::herbs:
			nameOfMat = "herbs";
			break;
		case materials::ores:
			nameOfMat = "ores";
			break;
		case materials::cloth:
			nameOfMat = "cloth";
			break;
		case materials::essence:
			nameOfMat = "essence";
			break;
		}
		out << nameOfMat << ": " << in.mats[i].second;
	}
	return out;
}