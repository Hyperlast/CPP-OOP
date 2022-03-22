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
#include "Deck.hpp"

Deck::Deck()
{
	this->DeckName = " ";
}

Deck::Deck(std::string Name, std::vector<MonsterCard> MonsterCards, std::vector<MagicCard> MagicCards, std::vector<PendulumCard> PendingCards)
{
	this->DeckName = Name;
	this->Deck_MonsterCards = MonsterCards;
	this->Deck_MagicCards = MagicCards;
	this->Deck_PendulumCards = PendingCards;
}

std::string Deck::getDeckName()const
{
	return this->DeckName;
}

int Deck::getMonsterCardCount()const
{
	return this->Deck_MonsterCards.size();
}

int Deck::getMagicCardCount()const
{
	return this->Deck_MagicCards.size();
}

int Deck::getPendulumCardCount()const
{
	return this->Deck_PendulumCards.size();
}

void Deck::setDeckname(std::string Name)
{
	this->DeckName = Name;
}

void Deck::addMonsterCard(MonsterCard addMonster)
{
	this->Deck_MonsterCards.push_back(addMonster);
}

void Deck::addMagicCard(MagicCard addMagic)
{
	this->Deck_MagicCards.push_back(addMagic);
}

void Deck::addPendulumCard(PendulumCard addPend)
{
	this->Deck_PendulumCards.push_back(addPend);
}

void Deck::ChangeMonsterCard(int IDX, MonsterCard ChangeMon)
{
	this->Deck_MonsterCards[IDX] = ChangeMon;
}

void Deck::ChangeMagicCard(int IDX, MagicCard ChangeMag)
{
	this->Deck_MagicCards[IDX] = ChangeMag;
}

void Deck::ChangePendulumCard(int IDX, PendulumCard ChangePend)
{
	this->Deck_PendulumCards[IDX] = ChangePend;
}

void Deck::DestroyDeck()
{
	this->Deck_MonsterCards.clear();
	this->Deck_MagicCards.clear();
	this->Deck_PendulumCards.clear();
}

std::ostream& operator<<(std::ostream& out, const Deck& OutDek)
{
	out << OutDek.getDeckName() << "|" << OutDek.getMonsterCardCount() << "|" <<OutDek.getMagicCardCount() << "|" << OutDek.getPendulumCardCount()<<"\n";
	for ( int i = 0; i < OutDek.getMonsterCardCount(); ++i)
	{
		out << OutDek.Deck_MonsterCards[i].getName()<< "|" << OutDek.Deck_MonsterCards[i].getEffect() << "|"
			<< OutDek.Deck_MonsterCards[i].getAttack()<< "|" << OutDek.Deck_MonsterCards[i].getDefense()<<"\n";
	}
	for ( int i = 0; i < OutDek.getMagicCardCount(); ++i)
	{
		out << OutDek.Deck_MagicCards[i].getName() << "|" << OutDek.Deck_MagicCards[i].getEffect() << "|";
		switch (OutDek.Deck_MagicCards[i].getType())
		{
		case Type::trap:
			out << "TRAP";
			break;
		case Type::buff:
			out << "BUFF";
			break;
		case Type::spell:
			out << "SPELL";
			break;
		case Type::None:
			out << "NONE";
			break;
		}
		out << "\n";
	}
	for (int i = 0; i < OutDek.getPendulumCardCount(); ++i)
	{
		out << OutDek.Deck_PendulumCards[i].getName() << "|" << OutDek.Deck_PendulumCards[i].getEffect() << "|" << OutDek.Deck_PendulumCards[i].getAttack()
			<< "|" << OutDek.Deck_PendulumCards[i].getDefense() << "|" << OutDek.Deck_PendulumCards[i].getScale() << "|";
		switch (OutDek.Deck_PendulumCards[i].getType())
		{
		case Type::trap:
			out << "TRAP";
			break;
		case Type::buff:
			out << "BUFF";
			break;
		case Type::spell:
			out << "TRAP";
			break;
		case Type::None:
			out << "NONE";
			break;
		}
		out << "\n";
	}
	return out;
}
