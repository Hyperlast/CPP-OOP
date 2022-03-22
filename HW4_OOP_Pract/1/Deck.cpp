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
#include "Deck.hpp"
#include <algorithm>
Deck::Deck()
{
	this->DeckName = " ";
}

Deck::Deck(std::string Name, std::vector<Card*>DeckCards)
{
	this->DeckName = Name;
	this->DeckCards = DeckCards;
}

std::string Deck::getDeckName()const
{
	return this->DeckName;
}

int Deck::getMonsterCardCount()const
{
	int NumOfM = 0;
	for (unsigned int i = 0; i < this->DeckCards.size(); ++i)
	{
		MonsterCard* M_ptr = dynamic_cast<MonsterCard*>(this->DeckCards[i]);
		MagicCard* Mag_ptr = dynamic_cast<MagicCard*>(this->DeckCards[i]);
		if (M_ptr && !Mag_ptr)
		{
			NumOfM++;
		}
	}
	
	return NumOfM;
}

int Deck::getMagicCardCount()const
{
	int NumOfMag = 0;
	for (unsigned int i = 0; i < this->DeckCards.size(); ++i)
	{
		MagicCard* Mag_ptr = dynamic_cast<MagicCard*>(this->DeckCards[i]);
		MonsterCard* Monsterptr = dynamic_cast<MonsterCard*>(this->DeckCards[i]);
		if (Mag_ptr && !Monsterptr)
		{
			NumOfMag++;
		}
	}

	return NumOfMag;
}

int Deck::getPendulumCardCount()const
{
	int NumOfPend = 0;
	for (unsigned int i = 0; i < this->DeckCards.size(); ++i)
	{
		PendulumCard* Pend_ptr = dynamic_cast<PendulumCard*>(this->DeckCards[i]);
		if (Pend_ptr)
		{
			NumOfPend++;
		}
	}

	return NumOfPend;
}

int Deck::getCardCount() const
{
	return this->DeckCards.size();
}

void Deck::setDeckname(std::string Name)
{
	this->DeckName = Name;
}

void Deck::addCard(Card* addCard)
{
	MonsterCard* Monsterptr = dynamic_cast<MonsterCard*>(addCard);
	MagicCard* Magicptr = dynamic_cast<MagicCard*>(addCard);
	if (Monsterptr && Magicptr)
	{
		PendulumCard* Pendptr = dynamic_cast<PendulumCard*>(addCard);
		if (Pendptr)
		{
			this->DeckCards.push_back(new PendulumCard(*Pendptr));
			return;
		}
	}
	if (Monsterptr)
	{
		this->DeckCards.push_back(new MonsterCard(*Monsterptr));
	}
	
	if (Magicptr)
	{
		this->DeckCards.push_back(new MagicCard(*Magicptr));
	}
	
}

std::vector<Card*> Deck::getCards() const
{
	return this->DeckCards;
}

void Deck::ChangeCard(unsigned IDX, Card* Swapper)
{
	PendulumCard* Pend_ptr = dynamic_cast<PendulumCard*>(Swapper);
	PendulumCard* PendDeck_ptr = dynamic_cast<PendulumCard*>(this->DeckCards[IDX]);
	if (Pend_ptr && PendDeck_ptr)
	{
		std::cout << "PendulumCard Successfully changed";
		DeckCards[IDX] = new PendulumCard(*Pend_ptr);
	}
	if ((!Pend_ptr && PendDeck_ptr) || (Pend_ptr && !PendDeck_ptr))
	{
		return;
	}
	MonsterCard* Mon_ptr = dynamic_cast<MonsterCard*>(Swapper);
	MonsterCard* MonDeck_ptr = dynamic_cast<MonsterCard*>(this->DeckCards[IDX]);
	if (Mon_ptr && MonDeck_ptr)
	{
		std::cout << "MonsterCard Successfully changed";
		DeckCards[IDX] = new MonsterCard(*Mon_ptr);
	}
	if ((!Mon_ptr && MonDeck_ptr) || (Mon_ptr && !MonDeck_ptr))
	{
		return;
	}
	MagicCard* Mag_ptr = dynamic_cast<MagicCard*>(Swapper);
	MagicCard* MagDeck_ptr = dynamic_cast<MagicCard*>(this->DeckCards[IDX]);
	if (Mag_ptr && MagDeck_ptr)
	{
		std::cout << "MagicCard Successfully changed";
		DeckCards[IDX] = new MagicCard(*Mag_ptr);
	}
	if ((!Mag_ptr && MagDeck_ptr) || (Mag_ptr && !MagDeck_ptr))
	{
		return;
	}
}

void Deck::DestroyDeck()
{
	for (unsigned int i = 0; i < this->DeckCards.size(); ++i)
	{
		delete this->DeckCards[i];
		DeckCards.erase(DeckCards.begin() + i);
	}
}
void Deck::DeckShuffle()
{
	std::random_shuffle(this->DeckCards.begin(), this->DeckCards.end());
}

void Deck::display()
{
	for (unsigned int i = 0; i < this->DeckCards.size(); ++i)
	{
		this->DeckCards[i]->printf();
		std::cout << '\n';
	}

}

std::ostream& operator<<(std::ostream& out, const Deck& OutDek)
{
	out << OutDek.getDeckName()<<"|"<<OutDek.getCardCount() << "|" << OutDek.getMonsterCardCount() << "|" <<OutDek.getMagicCardCount() << "|" << OutDek.getPendulumCardCount()<<"\n";
	for (int i = 0; i < OutDek.getCardCount(); ++i)
	{
		MonsterCard* Monptr = dynamic_cast<MonsterCard*>(OutDek.DeckCards[i]);
		MagicCard*	Mag_Monptr = dynamic_cast<MagicCard*>(OutDek.DeckCards[i]);
		if (Monptr && !Mag_Monptr)
		{
			out << OutDek.DeckCards[i]->getName() << "|" << OutDek.DeckCards[i]->getEffect() << "|"
				<<OutDek.DeckCards[i]->getRarity() <<"|"<< Monptr->getAttack() << "|"
				<< Monptr->getDefense() << "\n";
		}
	}
	
	for (int i = 0; i < OutDek.getCardCount(); ++i)
	{
		MonsterCard* Mag_Monptr = dynamic_cast<MonsterCard*>(OutDek.DeckCards[i]);
		MagicCard* Magptr = dynamic_cast<MagicCard*>(OutDek.DeckCards[i]);
		if(Magptr && !Mag_Monptr)
		{
			out << OutDek.DeckCards[i]->getName() << "|" << OutDek.DeckCards[i]->getEffect() << "|"
				<< OutDek.DeckCards[i]->getRarity() << "|";
			switch (Magptr->getType())
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
	}
	
	for (int i = 0; i < OutDek.getCardCount(); ++i)
	{
		PendulumCard* Pendptr = dynamic_cast<PendulumCard*>(OutDek.DeckCards[i]);
		if (Pendptr)
		{
			out << OutDek.DeckCards[i]->getName() << "|" << OutDek.DeckCards[i]->getEffect() << "|"
				<<OutDek.DeckCards[i]->getRarity()<<"|" << Pendptr->getAttack()
				<< "|" << Pendptr->getDefense() << "|" << Pendptr->getScale() << "|";
			switch (Pendptr->getType())
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
	}
	return out;
	
}
