#include "ElectionResultsDatabase.hpp"
#include <string>

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
    std::string buffer;
    std::ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file,buffer))
        {
            std::string temp;
            temp = buffer;
            int number1 = 0;
            int number2 = 0;
            int number3 = 0;
            for(unsigned int i=0 ; temp[i] != 32 ; ++i)
            {
                if ((temp[i] <= '9') && (temp[i] >= '0'))
                {
                    number1 = number1 * 10 + temp[i] - 48;
                }
            }
            for (unsigned int i = 0, j = 0; j < 2; ++i)
            {
                if ((j == 1) && (temp[i] <= '9') && (temp[i] >= '0'))
                {  
                    number2 = number2 * 10 + temp[i] - 48;
                }
                if (temp[i] == 32)
                {
                    j++;
                }

            }
            for (unsigned int i = 0, j = 0;i<temp.size() ; ++i)
            {
                if ((j == 2) && (temp[i] <= '9') && (temp[i] >= '0'))
                {
                    number3 = number3 * 10 + temp[i] - 48;
                }
                if (temp[i] == 32)
                {
                    j++;
                }
                
            }
            SectionVotes Section(number1, number2, number3);
            this->votes.push_back(Section);
        }
    }
    if (!file.is_open())
    {
        std::cout << "Error" << std::endl;
    }

    file.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
    return this->votes.size();
}

int ElectionResultsDatabase::votesForParty(Party Choice) const
{
    int temp=0;
    for (unsigned int i = 0; i < this->votes.size(); ++i)
    {
        temp += votes[i].votesForParty(Choice);
    }
    return temp;
}

Party ElectionResultsDatabase::winningParty() const
{
    int temp1=votesForParty(PARTY1);

    int temp2=votesForParty(PARTY2);
   
    int temp3=votesForParty(PARTY3);
   
    if (temp1 >= temp2 && temp1 >= temp3)
    {
        return Party::PARTY1;
    }
    if (temp2 > temp1 && temp2 >= temp3)
    {
        return Party::PARTY2;
    }
    if (temp3 > temp1 && temp3 > temp2)
    {
        return Party::PARTY3;
    }
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& Drop)
{
    for (unsigned int i = 0; i < Drop.votes.size(); ++i)
    {
        out << Drop.votes[i]<<" ";
        out << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& Cop)
{
    SectionVotes T;
    SectionVotes Temp;
    in >> T;
    while (T > Temp)
    {
        Cop.votes.push_back(T);
        in >> T;
    }
    return in;
}
