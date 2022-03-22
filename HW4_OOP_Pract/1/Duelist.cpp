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
#include "Duelist.hpp"

Duelist::Duelist()
{
	this->DuelistName = " ";
}

Duelist::Duelist(std::string Name)
{
	this->DuelistName = Name;
}

void Duelist::display()const
{
	std::cout << this->DuelistDeck;
}

std::string Duelist::getName() const
{
	return this->DuelistName;
}

Deck& Duelist::getDeck()
{
	return this->DuelistDeck;
}

bool Duelist::saveDeck(const char* filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		file << getDeck();
		return true;
	}

	if (!file.is_open())
	{
		return false;
	}
	return true;
}

bool Duelist::loadDeck(const char* filename)
{
	this->DuelistDeck.DestroyDeck();
	std::string buffer;
	std::ifstream file(filename);
	if (file.is_open())
	{
		int line = 1;
		int NumOfMRows = 0;
		int NumOfMagRows = 0;
		int NumOfPenRows = 0;

		while (getline(file, buffer))
		{
			if (line == 1)
			{
				int tempLine = 0;
				std::string DeckName;
				for (unsigned int i = 0; i < buffer.size(); ++i)
				{
					if (buffer[i] == '|')
					{
						tempLine++;
					}

					if (tempLine < 1)
					{
						DeckName += buffer[i];
					}

					if (tempLine == 2 && buffer[i] != '|')
					{
						NumOfMRows = (NumOfMRows * 10 + (buffer[i] - '0'));
					}

					if (tempLine == 3 && buffer[i] != '|')
					{
						NumOfMagRows = (NumOfMagRows * 10 + (buffer[i] - '0'));
					}

					if (tempLine == 4 && buffer[i] != '|')
					{
						NumOfPenRows = (NumOfPenRows * 10 + (buffer[i] - '0'));
					}
				}

				getDeck().setDeckname(DeckName);
			}
			if ((line > 1) && (line <= (NumOfMRows + 1)))
			{
				int tempLinesM = 0;
				std::string name;
				std::string effect;
				unsigned int ad = 0;
				unsigned int def = 0;
				unsigned int Rare = 0;

				for (unsigned int i = 0; i < buffer.size(); ++i)
				{
					if (buffer[i] == '|')
					{
						tempLinesM++;
					}

					if (tempLinesM < 1)
					{
						name += buffer[i];
					}

					if (tempLinesM == 1 && buffer[i] != '|')
					{
						effect += buffer[i];
					}

					if (tempLinesM == 2 && buffer[i] != '|')
					{
						Rare = (Rare * 10 + (buffer[i] - '0'));
					}

					if (tempLinesM == 3 && buffer[i] != '|')
					{
						ad = (ad * 10 + (buffer[i] - '0'));
					}

					if (tempLinesM == 4 && buffer[i] != '|')
					{
						def = (def * 10 + (buffer[i] - '0'));
					}
				}

				MonsterCard TempMons(name, effect, ad, def,Rare);
				Card* TempCard = &TempMons;
				getDeck().addCard(TempCard);
			}
			if ((line > (NumOfMRows + 1)) && (line <= (NumOfMRows + 1 + NumOfMagRows)))
			{
				int tempLinesMAG = 0;
				std::string nameM;
				std::string effectM;
				std::string TypeM;
				unsigned Rarity=0 ; 

				for (unsigned int i = 0; i < buffer.size(); ++i)
				{
					if (buffer[i] == '|')
					{
						tempLinesMAG++;
					}

					if (tempLinesMAG < 1)
					{
						nameM += buffer[i];
					}

					if (tempLinesMAG == 1 && buffer[i] != '|')
					{
						effectM += buffer[i];
					}

					if (tempLinesMAG == 2 && buffer[i] != '|')
					{
						Rarity = (Rarity * 10 + (buffer[i] - '0'));
					}

					if (tempLinesMAG == 3 && buffer[i] != '|')
					{
						TypeM += buffer[i];
					}

				}
				if (TypeM == "BUFF")
				{
					MagicCard TempMag(nameM, effectM, Type::buff, Rarity);
					Card* temp = &TempMag;
					getDeck().addCard(temp);
				}
				if (TypeM == "TRAP")
				{
					MagicCard TempMag(nameM, effectM, Type::trap, Rarity);
					Card* temp = &TempMag;
					getDeck().addCard(temp);
				}
				if (TypeM == "SPELL")
				{
					MagicCard TempMag(nameM, effectM, Type::spell, Rarity);
					Card* temp = &TempMag;
					getDeck().addCard(temp);
				}
				if (TypeM == "NONE")
				{
					MagicCard TempMag(nameM, effectM, Type::None, Rarity);
					Card* temp = &TempMag;
					getDeck().addCard(temp);
				}

			}
			if ((line > (NumOfMRows + 1 + NumOfMagRows)) && line <= (NumOfMRows + 1 + NumOfMagRows + NumOfPenRows))
			{
				int tempLinesP = 0;
				std::string nameP;
				std::string effectP;
				std::string TypeP;
				unsigned int adP = 0;
				unsigned int defP = 0;
				unsigned int Scale = 1;
				unsigned int PendRare = 0;
				for (unsigned int i = 0; i < buffer.size(); ++i)
				{
					if (buffer[i] == '|')
					{
						tempLinesP++;
					}

					if (tempLinesP < 1)
					{
						nameP += buffer[i];
					}

					if (tempLinesP == 1 && buffer[i] != '|')
					{
						effectP += buffer[i];
					}

					if (tempLinesP == 2 && buffer[i] != '|')
					{
						PendRare = (PendRare * 10 + (buffer[i] - '0'));
					}

					if (tempLinesP == 3 && buffer[i] != '|')
					{
						adP = (adP * 10 + (buffer[i] - '0'));
					}

					if (tempLinesP == 4 && buffer[i] != '|')
					{
						defP = (defP * 10 + (buffer[i] - '0'));
					}

					if (tempLinesP == 5 && buffer[i] != '|')
					{
						Scale = (Scale * 10 + (buffer[i] - '0'));
					}
					if (tempLinesP == 6 && buffer[i] != '|')
					{
						TypeP += buffer[i];
					}
				}
				if (TypeP == "BUFF")
				{
					PendulumCard TempPend(nameP, effectP, adP, defP, Type::buff, Scale, PendRare);
					Card* temp = &TempPend;
					getDeck().addCard(temp);
				}
				if (TypeP == "TRAP")
				{
				    PendulumCard TempPend(nameP, effectP, adP, defP, Type::trap, Scale, PendRare);
					Card* temp = &TempPend;
					getDeck().addCard(temp);
				}
				if (TypeP == "SPELL")
				{
					PendulumCard TempPend(nameP, effectP, adP, defP, Type::spell, Scale, PendRare);
					Card* temp = &TempPend;
					getDeck().addCard(temp);
				}
				if (TypeP == "NONE")
				{
					PendulumCard TempPend(nameP, effectP, adP, defP, Type::None, Scale, PendRare);
					Card* temp = &TempPend;
					getDeck().addCard(temp);
				}

			}

			line++;
		}

		return true;
	}

	if (!file.is_open())
	{
		return false;
	}
return true;
}

void Duelist::Duel(Duelist& RHD)
{
	if (this->DuelistDeck.getCardCount() != RHD.getDeck().getCardCount())
	{
		if (this->DuelistDeck.getCardCount() > RHD.getDeck().getCardCount())
		{
			std::cout << "\nSecond duelist's deck has less cards--> "<< this->DuelistDeck.getCardCount() - RHD.getDeck().getCardCount()<<":\n";
		}
		if (this->DuelistDeck.getCardCount() < RHD.getDeck().getCardCount())
		{
			std::cout << "\nFirst duelist's deck has less cards--> " <<  RHD.getDeck().getCardCount() - this->DuelistDeck.getCardCount()  << ":\n";
		}
		return;
	}

	if (this->DuelistDeck.getCardCount() == RHD.getDeck().getCardCount())
	{
		unsigned Duelist1_Points = 0;
		unsigned Duelist2_Points = 0;

		this->DuelistDeck.DeckShuffle();
		RHD.getDeck().DeckShuffle();
		std::cout << "LET THE BATTLE BEGIN!\n\n\n";
		for (int i = 0; i < this->DuelistDeck.getCardCount(); ++i)
		{
			if (*DuelistDeck.getCards()[i] > *RHD.getDeck().getCards()[i])
			{
				std::cout << "Round " << i + 1 << " wins " << this->DuelistName<<'\n';
				Duelist1_Points++;
				std::cout << this->DuelistName << " has " << Duelist1_Points << " points:::\n";
				std::cout << RHD.getName() << " has " << Duelist2_Points << " points:::\n";
			}
			else
			{
				if(*DuelistDeck.getCards()[i] < *RHD.getDeck().getCards()[i])
				{
					std::cout << "Round " << i + 1 << " wins " << RHD.getName() << '\n';
					Duelist2_Points++;
					std::cout << this->DuelistName << " has " << Duelist1_Points << " points:::\n";
					std::cout << RHD.getName() << " has " << Duelist2_Points << " points:::\n";
				}
				else
				{
					std::cout << "Round " << i + 1 << " is a draw!!!\n";
				}
			}
		}
		if (Duelist1_Points > Duelist2_Points)
		{
			std::cout << "THE WINNER OF THE DUEL IS...\n"
				<< this->DuelistName<<" with "<< Duelist1_Points-Duelist2_Points<<" more!!!\n";
		}
		if (Duelist1_Points < Duelist2_Points)
		{
			std::cout << "THE WINNER OF THE DUEL IS...\n"
				<< RHD.getName() << " with " << Duelist2_Points - Duelist1_Points << " more!!!\n";
		}
		if (Duelist1_Points == Duelist2_Points)
		{
			std::cout << "THE WINNER OF THE DUEL IS...\n"
				<<"NO ONE IT'S A DRAAAW!!!!\n"
				<<"EACH DUELIST HAS "<< Duelist1_Points<<" AMOUNT OF POINTS\n";
		}
	}
}
