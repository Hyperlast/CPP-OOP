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
#include "Card.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include <vector>
class Deck
{
private:
	std::string DeckName;
	std::vector<Card*> DeckCards;
public:
	Deck();
	Deck(std::string Name,std::vector<Card*>DeckCards);
	
	std::string getDeckName()const;
	int getMonsterCardCount()const;
	int getMagicCardCount()const;
	int getPendulumCardCount()const;
	int getCardCount()const;
	std::vector<Card*> getCards()const;

	void setDeckname(std::string);

	void addCard(Card*);

	

	void ChangeCard(unsigned,Card*);

	void DestroyDeck();

	void DeckShuffle();

	friend std::ostream& operator<<(std::ostream& out, const Deck&);
	
	void display();

	~Deck()=default;
};
