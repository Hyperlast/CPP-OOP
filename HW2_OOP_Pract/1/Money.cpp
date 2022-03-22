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
#include "Money.hpp"

Money::Money()
{
	std::pair<unsigned int, std::string> TempGold;
	TempGold.first = 0;
	TempGold.second = "gold";
	std::pair<unsigned int, std::string> TempSilv;
	TempSilv.first = 0;
	TempSilv.second = "silver";
	this->Balance.push_back(TempGold);
	this->Balance.push_back(TempSilv);
}

Money::Money(std::vector<std::pair<unsigned int, std::string>> Money)
{
	for (unsigned int i = 0; i < Money.size(); ++i)
	{
		std::pair<unsigned int, std::string> Temp;
		Temp.first = Money[i].first;
		Temp.second = Money[i].second;
		if (i == 1 && Temp.first >= 100)
		{
			unsigned int temp2 = 0;
			temp2 = Temp.first / 100;
			Balance[0].first += temp2;
			Temp.first = Temp.first % 100;
		}
		this->Balance.push_back(Temp);
	}
}

Money::Money(const Money& Copy)
{
	for (unsigned int i = 0; i < Copy.Balance.size(); ++i)
	{
		std::pair<unsigned int, std::string> Temp;
		Temp.first = Copy.Balance[i].first;
		Temp.second = Copy.Balance[i].second;
		this->Balance.push_back(Temp);
	}
}

void Money::addMoney(unsigned int amount,std::string type )
{
	if (type == "gold")
	{
		Balance[0].first += amount;
	}
	if (type == "silver")
	{
		Balance[1].first += amount;
		if (Balance[1].first >= 100)
		{
			unsigned int temp = 0;
			temp = Balance[1].first/100;
			Balance[0].first += temp;
			Balance[1].first = Balance[1].first % 100;
		}
	}

}

void Money::takeMoney(unsigned int amount, std::string type)
{
	if (type == "gold")
	{
		if ((amount <= Balance[0].first))
		{
			Balance[0].first -= amount;
		}
	}
	if(type=="silver")
	{
		if ((Balance[1].first >= amount))
		{
			Balance[1].first -= amount;
		}
		else
		{
			if (Balance[0].first != 0)
			{
				unsigned int temp = 0;
				temp += Balance[0].first * 100;
				temp += Balance[1].first;
				temp -= amount;
				if (temp > 0)
				{
					Balance[0].first = temp / 100;
					Balance[1].first = temp % 100;
				}
			}
			
		}
	}
}

void Money::deleteMoney()
{
	Balance[0].first = 0;
	Balance[1].first = 0;
}

void Money::Printf()const
{
	std::cout << Balance[0].first << " " << Balance[0].second<<std::endl;
	std::cout << Balance[1].first << " " << Balance[1].second << std::endl;
}

int Money::getSlots()
{
	return 0;
}

Money& Money::operator+=(const Money& ADD)
{
	if (this != &ADD)
	{
		this->Balance[0].first += ADD.Balance[0].first;
		Balance[1].first += ADD.Balance[1].first;
		if (Balance[1].first >= 100)
		{
			unsigned int temp = 0;
			temp = Balance[1].first / 100;
			Balance[0].first += temp;
			Balance[1].first = Balance[1].first % 100;
		}
	}
	return *this;
}

Money& Money::operator-=(const Money& SUB)
{
	if (this != &SUB)
	{
		if ((this->Balance[0].first - SUB.Balance[0].first) >= 0)
		{
			this->Balance[0].first -= SUB.Balance[0].first;
		}
		if ((Balance[1].first >= SUB.Balance[1].first))
		{
			Balance[1].first -= SUB.Balance[1].first;
		}
		else
		{
			if (Balance[0].first != 0)
			{
				unsigned int temp = 0;
				temp += Balance[0].first * 100;
				temp += Balance[1].first;
				temp -= SUB.Balance[1].first;
				if (temp > 0)
				{
					Balance[0].first = temp / 100;
					Balance[1].first = temp % 100;
				}
			}

		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Money& in)
{
	for (unsigned int i = 0; i < in.Balance.size(); ++i)
	{
		out << in.Balance[i].first << " " << in.Balance[i].second;
	}
	return out;
}
