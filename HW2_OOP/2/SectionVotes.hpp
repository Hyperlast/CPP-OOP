#pragma once
#include<vector>
#include<iostream>
#include<fstream>
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
private:
    std::vector<int> Votes;

public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);
    SectionVotes(const SectionVotes&);
    int votesForParty(Party) const;
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes&);
    friend std::istream& operator>>(std::istream& in, SectionVotes&);
    bool operator>(const SectionVotes&)const;
};
