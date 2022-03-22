#include "SectionVotes.hpp"

SectionVotes::SectionVotes()
{
	this->Votes.push_back(0);
	this->Votes.push_back(0);
	this->Votes.push_back(0);
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	this->Votes.push_back(party1Votes);
	this->Votes.push_back(party2Votes);
	this->Votes.push_back(party3Votes);
}

SectionVotes::SectionVotes(const SectionVotes& Copy)
{
	for (unsigned int i = 0; i < 3; ++i)
	{
		this->Votes.push_back(Copy.Votes[i]);
	}
}

int SectionVotes::votesForParty(Party Choice) const
{
	int temp = this->Votes[Choice];
	return temp;
}

bool SectionVotes::operator>(const SectionVotes& Diff) const
{
	for (unsigned int i = 0; i < 3; ++i)
	{
		if (this->Votes[i] < Diff.Votes[i])
		{
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out,const SectionVotes& Temp)
{
	for (unsigned int i = 0; i < 3; ++i)
	{
		out << Temp.Votes[i] << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, SectionVotes& Temp) 
{
	unsigned int num=-1;
	for (unsigned int i = 0; i < 3; ++i)
	{
		in >> num;
		Temp.Votes[i] = num;
	}
	return in;
}
