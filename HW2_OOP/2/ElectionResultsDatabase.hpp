#pragma once
#include "SectionVotes.hpp"
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{
    std::vector<SectionVotes> votes;
public:

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase&);
    friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase&);
};