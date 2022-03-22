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
#include "Armor.hpp"
#include "Materials.hpp"
#include "Money.hpp"
#include "Weapons.hpp"

template<typename T>
class Inventory
{
private:
	T storage;
	//Backpack
	//Equipment
public:
	Inventory();
	Inventory(T _storage);
	Inventory(const Inventory&);
	~Inventory() = default;

	void _printf();
	friend std::ostream& operator<<(std::ostream& out,const Inventory& in);
	bool operator==(Inventory& Same);
	bool operator!=(Inventory& Diff);
};



template<typename B>
class Backpack
{
private:
	B Bag;
	//MONEY
	//MATERIALS
	unsigned int BagSlots; //max 16 slots
public:
	Backpack();
	Backpack(B);
	Backpack(const Backpack&);

	int SlotsTaken();
	bool isEmpty()const;
	bool isFull()const;
	void NullBag();
	void addToBag(B);
	void RemoveFromBag(B);
	
	void printf();
	friend std::ostream& operator<<(std::ostream& out, const Backpack& in);
};

template<typename E>
class Equipment
{
private:
	std::vector<E> Equip;
	//WEAPON
	//ARMOR
	unsigned int EqSlots;// max 24
public:
	Equipment();
	Equipment(std::vector<E>);
	Equipment(const Equipment&);

	int SlotsTaken()const;
	bool isFull()const;
	bool isEmpty()const;
	void RemoveEquipment();
	void addEquip(E);
	void RemEquip(E);
	E bestEquipment();

	void printf();

	bool operator == (const Equipment&);
	bool operator != (const Equipment&);
	friend std::ostream& operator<<(std::ostream& out, const Equipment& in);

	~Equipment() = default;
};


template<typename E>
Equipment<E>::Equipment()
{
	this->EqSlots = 0;
	E temp;
	Equip.push_back(temp);
}

template<typename E>
Equipment<E>::Equipment(std::vector<E> ADD)
{
	unsigned int tempSlots = 0;
	for(unsigned int i=0;i<ADD.size();++i)
	{
		if (ADD[i].getSlots() + EqSlots <= 24)
		{
			Equip.push_back(ADD[i]);
			this->EqSlots += ADD[i].getSlots();
		}
	}
}

template<typename E>
Equipment<E>::Equipment(const Equipment& Copy)
{
	for (unsigned int i = 0; i < Copy.Equip.size(); ++i)
	{
		Equip.push_back(Copy.Equip[i]);
	}
	this->EqSlots = Copy.EqSlots;
}

template<typename E>
int Equipment<E>::SlotsTaken()const
{
	return this->EqSlots;
}

template<typename E>
bool Equipment<E>::isEmpty()const
{
	if (this->EqSlots == 0)
	{
		return true;
	}
	return false;
}

template<typename E>
bool Equipment<E>::isFull()const
{
	if (this->EqSlots == 24)
	{
		return true;
	}
	return false;
}

template<typename E>
void Equipment<E>::RemoveEquipment()
{
	for (unsigned int i = Equip.size(); i>0; --i)
	{
		Equip.pop_back();
	}
	this->EqSlots = 0;
}

template<typename E>
void Equipment<E>::addEquip(E temp)
{
	if (this->EqSlots + temp.getSlots() <= 24)
	{
		Equip.push_back(temp);
		this->EqSlots += temp.getSlots();
	}
}
template<typename E>
void Equipment<E>::RemEquip(E temp)
{
	for (unsigned int i = 0; i < this->Equip.size(); ++i)
	{
		if (temp == Equip[i])
		{
			this->EqSlots-=temp.getSlots();
			Equip.erase(Equip.begin() + i);
		}
	}

}

template<typename E>
 E Equipment<E>::bestEquipment()
{
	double Best = Equip[0].getScore();
	unsigned int idx = 0;
	for (unsigned int i = 0; i < Equip.size(); ++i)
	{
		if (Best < Equip[i].getScore())
		{
			Best = Equip[i].getScore();
			idx = i;
		}

	}
	return Equip[idx];
}

 template<typename E>
void Equipment<E>::printf()
 {
	for (unsigned int i = 0; i < this->Equip.size(); ++i)
	{
		Equip[i].Printf();
		std::cout << std::endl;
	}
 }

 template<typename E>
 bool Equipment<E>::operator==(const Equipment& Temp)
 {
	 double firstScore = 0;
	 double secondScore = 0;
	 for (unsigned int i = 0; i < Equip.size(); ++i)
	 {
		 firstScore += Equip[i].getScore();
	 }
	 for (unsigned int i = 0; i < Temp.Equip.size(); ++i)
	 {
		 secondScore += Temp.Equip[i].getScore();
	 }
	 if (firstScore == secondScore)
	 {
		 return true;
	 }	
	 return false;
 }

 template<typename E>
 bool Equipment<E>::operator!=(const Equipment& Temp)
 {
	 double firstScore = 0;
	 double secondScore = 0;
	 for (unsigned int i = 0; i < Equip.size(); ++i)
	 {
		 firstScore += Equip[i].getScore();
	 }
	 for (unsigned int i = 0; i < Temp.Equip.size(); ++i)
	 {
		 secondScore += Temp.Equip[i].getScore();
	 }
	 if (firstScore == secondScore)
	 {
		 return false;
	 }
	 return true;
 }

 template<typename B>
 Backpack<B>::Backpack()
 {
	 B temp;
	 this->Bag = temp;
	 this->BagSlots = 0;
 }

 template<typename B>
 Backpack<B>::Backpack(B any)
 {
	 if (any.getSlots() <= 16)
	 {
		 this->Bag = any;
		 this->BagSlots = any.getSlots();
	 }
	 if (any.getSlots() > 16)
	 {
		 B temp;
		 this->Bag = temp;
		 this->BagSlots = 0;
	 }
		
 }

 template<typename B>
 Backpack<B>::Backpack(const Backpack& Copy)
 {
	 this->Bag = Copy.Bag;
	 this->BagSlots = Copy.BagSlots;
 }

 template<typename B>
 int Backpack<B>::SlotsTaken()
 {
	 return this->BagSlots;
 }

 template<typename B>
 bool Backpack<B>::isEmpty() const
 {
	 if (this->BagSlots == 0)
	 {
		 return true;
	 }
	 return false;
 }

 template<typename B>
 bool Backpack<B>::isFull() const
 {
	 if (this->BagSlots == 16)
	 {
		 return true;
	 }
	 return false;
 }

 template<typename B>
 void Backpack<B>::NullBag()
 {
	 B temp;
	 this->Bag = temp;
	 this->BagSlots = 0;
 }

 template<typename B>
 void Backpack<B>::addToBag(B ADD)
 {
	 this->Bag += ADD;
	 this->BagSlots = Bag.getSlots();
 }

 template<typename B>
 void Backpack<B>::RemoveFromBag(B SUB)
 {
	 this->Bag -= SUB;
	 this->BagSlots = Bag.getSlots();
 }

 template<typename B>
 void Backpack<B>::printf()
 {
	 this->Bag.Printf();
 }

 Inventory<Backpack<Money>>::Inventory()
 {
	 Backpack<Money> temp = Backpack<Money>();
	 this->storage = temp;
 }

 Inventory<Backpack<Materials>>::Inventory()
 {
 	Backpack<Materials> temp = Backpack<Materials>();
 	this->storage = temp;
 }
 
 Inventory<Equipment<Weapon>>::Inventory()
 {
 	Equipment<Weapon> temp = Equipment<Weapon>();
 	this->storage = temp;
 }
 

 Inventory<Equipment<Armor>>::Inventory()
 {
	 Equipment<Armor> temp = Equipment<Armor>();
	 this->storage = temp;
 }

 template<typename T>
 Inventory<T>::Inventory(T _storage)
 {
	 this->storage = _storage;
 }

 template<typename T>
 Inventory<T>::Inventory(const Inventory& Copy)
 {
	 this->storage = Copy.storage;
 }
 template<typename T>
 void Inventory<T>::_printf()
 {
	 this->storage.printf();
 }
 template<typename T>
 bool Inventory<T>::operator==(Inventory<T>& Same)
 {
	 if (this->storage.SlotsTaken() == Same.storage.SlotsTaken())
	 {
		 return true;
	 }
	 return false;
 }

 template<typename T>
 bool Inventory<T>::operator!=(Inventory<T>& Diff)
 {
	 if (this->storage.SlotsTaken() != Diff.storage.SlotsTaken())
	 {
		 return true;
	 }
	 return false;
 }

 std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Materials>>& in)
 {
	 out << in.storage;
	 return out;
 }
 std::ostream& operator<<(std::ostream& out, const Inventory<Backpack<Money>>& in)
 {
	 out << in.storage;
	 return out;
 }
 std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Armor>>& in)
 {
	 out << in.storage;
	 return out;
 }
 std::ostream& operator<<(std::ostream& out, const Inventory<Equipment<Weapon>>& in)
 {
	 out << in.storage;
	 return out;
 }

 std::ostream& operator<<(std::ostream& out, const Backpack<Materials>& in)
 {
	 out << in.Bag;
	 return out;
 }
 std::ostream& operator<<(std::ostream& out, const Backpack<Money>& in)
 {
	 out << in.Bag;
	 return out;
 }
 std::ostream& operator<<(std::ostream& out, const Equipment<Armor>& in)
 {
	 for (unsigned int i = 0; i < in.Equip.size(); ++i)
	 {
		 out << in.Equip[i] <<" "<<in.EqSlots<< " \n";
	 }
	 return out;
 }
 std::ostream& operator<<(std::ostream& out, const Equipment<Weapon>& in)
 {
	 for (unsigned int i = 0; i < in.Equip.size(); ++i)
	 {
		 out << in.Equip[i] << " " << in.EqSlots << " \n";
	 }
	 return out;
 }

 //operator <<
