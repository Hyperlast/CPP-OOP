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
			if (line==1)
			{
				int tempLine = 0;
				std::string DeckName;
				for (int i = 0; i < buffer.size(); ++i)
				{
					if (buffer[i] == '|')
					{
						tempLine++;
					}

					if (tempLine < 1)
					{
						DeckName += buffer[i];
					}

					if (tempLine == 1 && buffer[i] != '|')
					{
						NumOfMRows = buffer[i]-'0';
					}

					if (tempLine == 2 && buffer[i] != '|')
					{
						NumOfMagRows = buffer[i]-'0';
					}

					if (tempLine == 3 && buffer[i] != '|')
					{
						NumOfPenRows = buffer[i]-'0';
					}
				}
				
				getDeck().setDeckname(DeckName);
			}
			if ((line > 1) && (line <= (NumOfMRows + 1)))
			{
				int tempLinesM = 0;
				std::string name;
				std::string effect;
				unsigned int ad=0;
				unsigned int def=0;
				for (int i = 0; i < buffer.size(); ++i)
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
						ad = (ad * 10 + (buffer[i] - '0'));
					}

					if (tempLinesM == 3 && buffer[i] != '|')
					{
						def = (def * 10 + (buffer[i] - '0'));
					}
				}
				MonsterCard TempMons(name, effect, ad, def);
				getDeck().addMonsterCard(TempMons);
			}
			if ((line > (NumOfMRows + 1)) && (line <= (NumOfMRows + 1 + NumOfMagRows)))
			{
				int tempLinesMAG = 0;
				std::string nameM;
				std::string effectM;
				std::string TypeM;
				for (int i = 0; i < buffer.size(); ++i)
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
						TypeM += buffer[i];
					}

				}
				if (TypeM == "BUFF")
				{
					MagicCard TempMag(nameM, effectM, Type::buff);
					getDeck().addMagicCard(TempMag);
				}
				if (TypeM == "TRAP")
				{
					MagicCard TempMag(nameM, effectM, Type::trap);
					getDeck().addMagicCard(TempMag);
				}
				if (TypeM == "SPELL")
				{
					MagicCard TempMag(nameM, effectM, Type::spell);
					getDeck().addMagicCard(TempMag);
				}
				if (TypeM == "NONE")
				{
					MagicCard TempMag(nameM, effectM, Type::None);
					getDeck().addMagicCard(TempMag);
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
				for (int i = 0; i < buffer.size(); ++i)
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
						adP = (adP * 10 + (buffer[i] - '0'));
					}

					if (tempLinesP == 3 && buffer[i] != '|')
					{
						defP = (defP * 10 + (buffer[i] - '0'));
					}

					if (tempLinesP == 4 && buffer[i] != '|')
					{
						Scale = (Scale * 10 + (buffer[i] - '0'));
					}
					if (tempLinesP == 5 && buffer[i] != '|')
					{
						TypeP += buffer[i];
					}
				}
				if (TypeP == "BUFF")
				{
					PendulumCard TempPend(nameP, effectP,adP,defP,Type::buff,Scale);
					getDeck().addPendulumCard(TempPend);
				}
				if (TypeP == "TRAP")
				{
					PendulumCard TempPend(nameP, effectP, adP, defP, Type::trap, Scale);
					getDeck().addPendulumCard(TempPend);
				}
				if (TypeP == "SPELL")
				{
					PendulumCard TempPend(nameP, effectP, adP, defP, Type::spell, Scale);
					getDeck().addPendulumCard(TempPend);
				}
				if (TypeP == "NONE")
				{
					PendulumCard TempPend(nameP, effectP, adP, defP, Type::None, Scale);
					getDeck().addPendulumCard(TempPend);
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
}