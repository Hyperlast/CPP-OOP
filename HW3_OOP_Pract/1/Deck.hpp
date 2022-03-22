/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 3
* @compiler VC
*/
#pragma once
#include "Base.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include <vector>
class Deck
{
private:
	std::string DeckName;
	std::vector<MonsterCard> Deck_MonsterCards;
	std::vector<MagicCard> Deck_MagicCards;
	std::vector<PendulumCard> Deck_PendulumCards;
public:
	Deck();
	Deck(std::string Name,std::vector<MonsterCard> MonsterCards,std::vector<MagicCard> MagicCards,std::vector<PendulumCard> PendingCards);
	
	std::string getDeckName()const;
	int getMonsterCardCount()const;
	int getMagicCardCount()const;
	int getPendulumCardCount()const;

	void setDeckname(std::string);
	void addMonsterCard(MonsterCard);
	void addMagicCard(MagicCard);
	void addPendulumCard(PendulumCard);

	void ChangeMonsterCard(int, MonsterCard);
	void ChangeMagicCard(int, MagicCard);
	void ChangePendulumCard(int, PendulumCard);

	void DestroyDeck();


	friend std::ostream& operator<<(std::ostream& out, const Deck&);

	~Deck()=default;
};
