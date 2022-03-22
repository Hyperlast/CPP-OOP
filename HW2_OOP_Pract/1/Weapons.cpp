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
#include "Weapons.hpp"
void Weapon::ChangeWeaponClass(WeaponTypeName Changer)
{
	switch (Changer)
	{
	case WeaponTypeName::dagger:
		this->WeaponClass = Changer;
		this->WeaponType = Type::OneHanded;
		break;
	case WeaponTypeName::staff:
		this->WeaponClass = Changer;
		this->WeaponType = Type::TwoHanded;
		break;
	default:
		this->WeaponClass = Changer;
		break;
	}
	if (this->WeaponType == Type::TwoHanded)
	{
		this->Slots = 2;
	}
	if (this->WeaponType == Type::OneHanded)
	{
		this->Slots = 1;
	}
}

void Weapon::ChangeWeaponType(Type R)
{
	this->WeaponType = R;
	this->WeaponScore = WeaponScoreCalc(this->WeaponType, this->HitDamage, this->Effect);
	if (R == Type::OneHanded)
	{
		this->Slots = 1;
	}
	if (R == Type::TwoHanded)
	{
		this->Slots = 2;
	}
}

void Weapon::Printf()const
{
	switch (this->WeaponType)
	{
	case Type::OneHanded:
		std::cout << "One-handed ";
		break;
	case Type::TwoHanded:
		std::cout << "Two-handed ";
		break;
	}
	switch (this->WeaponClass)
	{
	case WeaponTypeName::axe:
		std::cout << "Axe";
		break;
	case WeaponTypeName::sword:
		std::cout << "Sword";
		break;
	case WeaponTypeName::dagger:
		std::cout << "dagger";
		break;
	case WeaponTypeName::mace:
		std::cout << "mace";
		break;
	case WeaponTypeName::staff:
		std::cout << "staff";
		break;
	}
	std::cout << std::endl << this->HitDamage.first << " Min and " << this->HitDamage.second << " Max dmg with these effects:" << std::endl;
	for(unsigned int i=0;i<this->Effect.size();++i)
	{
		std::cout << "EffectName: " << Effect[i].first << '\t';
		std::cout << "EffectDmg: " << Effect[i].second << std::endl;
	}
	
}

Weapon& Weapon::operator=(const Weapon& CopyWeapon)
{
	if (this != &CopyWeapon)
	{
		this->WeaponClass = CopyWeapon.WeaponClass;
		this->WeaponType = CopyWeapon.WeaponType;
		this->HitDamage = CopyWeapon.HitDamage;
		for (unsigned int i = 0; i < CopyWeapon.Effect.size(); ++i)
		{
			std::pair<std::string, unsigned int>Temp;
			Temp.first = CopyWeapon.Effect[i].first;
			Temp.second = CopyWeapon.Effect[i].second;
			this->Effect.push_back(Temp);
		}
		this->WeaponScore = CopyWeapon.WeaponScore;
		this->Slots = CopyWeapon.Slots;
	}
	return *this;
}

bool Weapon::operator==(const Weapon& Temp)
{
	if (this->WeaponClass != Temp.WeaponClass)
		return 0;
	if (this->WeaponType != Temp.WeaponType)
		return 0;
	if (this->HitDamage != Temp.HitDamage)
		return 0;
	if (this->WeaponScore != Temp.WeaponScore)
		return 0;
	if (this->Effect.size() != Temp.Effect.size())
		return 0;
	for (unsigned int i = 0; i < Effect.size(); ++i)
	{
		if (Effect[i] != Temp.Effect[i])
			return 0;
	}
	return 1;
}

double Weapon::WeaponScoreCalc(Type T1,std::pair<unsigned int, unsigned int> &ScoreHitDamage, std::vector<std::pair<std::string, unsigned int>> &ScoreEffects)
{
	double TempCalc=0;
	TempCalc+=ScoreHitDamage.first;
	TempCalc+=ScoreHitDamage.second;
	TempCalc /= 2;
	for (unsigned int i = 0; i < ScoreEffects.size(); ++i)
	{
		TempCalc += ScoreEffects[i].second;
	}
	if (T1 == Type::OneHanded)
	{
		TempCalc *= 0.75;
		return TempCalc;
	}
	TempCalc *= 1.5;

	return TempCalc;
}

Weapon::Weapon()
{
	this->WeaponClass = WeaponTypeName::Default;
	this->WeaponType = Type::Default;
	this->HitDamage.first = 0;
	this->HitDamage.second = 0;
	std::pair<std::string, unsigned int>Temp;
	Temp.first = "\0";
	Temp.second = 0;
	this->Effect.push_back(Temp);
	this->WeaponScore = 0;
	this->Slots = 0;
}

Weapon::Weapon(Type T,WeaponTypeName Class,std::pair<unsigned int, unsigned int> addHitDamage, std::vector<std::pair<std::string, unsigned int>> addEffects)
{
	this->WeaponClass = Class;
	if (this->WeaponClass == WeaponTypeName::staff)
	{
		this->WeaponType = Type::TwoHanded;
	}
	if (this->WeaponClass == WeaponTypeName::dagger)
	{
		this->WeaponType = Type::OneHanded;
	}
	else
	{
		this->WeaponType = T;
	}
	this->HitDamage.first = addHitDamage.first;
	this->HitDamage.second = addHitDamage.second;
	for (unsigned int i = 0; i < addEffects.size(); ++i)
	{
		std::pair<std::string, unsigned int>Temp;
		Temp.first = addEffects[i].first;
		Temp.second = addEffects[i].second;
		this->Effect.push_back(Temp);
	}
	this->WeaponScore = WeaponScoreCalc(T, addHitDamage, addEffects);
	if (this->WeaponType == Type::TwoHanded)
	{
		this->Slots = 2;
	}
	if (this->WeaponType == Type::OneHanded)
	{
		this->Slots = 1;
	}
}

Weapon::Weapon(const Weapon& addWeapon)
{
	this->WeaponClass = addWeapon.WeaponClass;
	this->WeaponType = addWeapon.WeaponType;
	this->HitDamage.first = addWeapon.HitDamage.first;
	this->HitDamage.second = addWeapon.HitDamage.second;
	for (unsigned int i = 0; i < addWeapon.Effect.size(); ++i)
	{
		std::pair<std::string, unsigned int>Temp;
		Temp.first = addWeapon.Effect[i].first;
		Temp.second = addWeapon.Effect[i].second;
		this->Effect.push_back(Temp);
	}
	this->WeaponScore = addWeapon.WeaponScore;
	this->Slots = addWeapon.Slots;
}

void Weapon::addWeaponEffect(std::string addName, unsigned int addPower)
{
	std::pair<std::string, unsigned int> NewEffect;
	NewEffect.first = addName;
	NewEffect.second = addPower;
	bool flag = false;
	for (unsigned int i = 0; i < Effect.size(); ++i)
	{
		if ((Effect[i].first == NewEffect.first)&&(Effect[i].second == NewEffect.second))
		{
			Effect[i].second = NewEffect.second;
			flag = true;
		}
	}
	if (flag)
	{
		this->WeaponScore = WeaponScoreCalc(this->WeaponType, this->HitDamage, this->Effect);
	}
	else
	{
		this->Effect.push_back(NewEffect);
		this->WeaponScore = WeaponScoreCalc(this->WeaponType, this->HitDamage, this->Effect);
	}
	
}

void Weapon::deleteWeaponEffect(std::string Deleter)
{
	for (unsigned int i = 0; i < Effect.size(); ++i)
	{
		if (Effect[i].first == Deleter)
		{
			Effect.erase(Effect.begin() + i);
		}
	}
	this->WeaponScore = WeaponScoreCalc(this->WeaponType, this->HitDamage, this->Effect);
}

void Weapon::changePowerOfEffect(std::string Name, unsigned int ChangePow)
{
	for (unsigned int i = 0; i < this->Effect.size(); ++i)
	{
		if (Effect[i].first == Name)
		{
			Effect[i].second = ChangePow;
		}
	}
	this->WeaponScore = WeaponScoreCalc(this->WeaponType, this->HitDamage, this->Effect);
}

int Weapon::getWeaponType()
{
	switch (this->WeaponType)
	{
	case Type::OneHanded:
		return 0;
		break;
	case Type::TwoHanded:
		return 1;
		break;
	}
	return 0;
}

double Weapon::getScore()
{
	return this->WeaponScore;
}

int Weapon::getSlots()
{
	return this->Slots;
}

std::ostream& operator<<(std::ostream& out, const Weapon& in)
{
	std::string WType;
	switch (in.WeaponType)
	{
	case Type::OneHanded:
		WType = "One-handed";
		break;
	case Type::TwoHanded:
		WType = "Two-handed";
		break;
	}
	out << WType << " ";
	std::string WClass;
	switch (in.WeaponClass)
	{
	case WeaponTypeName::axe:
		WClass = "Axe";
		break;
	case WeaponTypeName::sword:
		WClass = "Sword";
		break;
	case WeaponTypeName::dagger:
		WClass = "Dagger";
		break;
	case WeaponTypeName::mace:
		WClass = "Mace";
		break;
	case WeaponTypeName::staff:
		WClass = "Staff";
		break;
	}
	out << WClass << " ";
	for (unsigned int i = 0; i < in.Effect.size(); ++i)
	{
		out << "Effect: " << in.Effect[i].first << " " << in.Effect[i].second;
	}
	out << " \nand dmg min of " << in.HitDamage.first << " and max of " << in.HitDamage.second;
	return out;
}
