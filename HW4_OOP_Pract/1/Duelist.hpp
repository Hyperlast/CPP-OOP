/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 4
* @compiler VC
*/
#pragma once
#include "Deck.hpp"
#include "Card.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include <fstream>

class Duelist
{
private:
	std::string DuelistName;
	Deck DuelistDeck;
public:
	Duelist();
	Duelist(std::string Name);
	
	void display()const;
	std::string getName()const;
	Deck& getDeck();

	bool saveDeck(const char*);
	bool loadDeck(const char*);

	void Duel(Duelist&);
};