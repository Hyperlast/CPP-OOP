/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Kalin Borisov
* @idnumber 62580
* @task 2
* @compiler VC
*/
#include "DeckDuelist.hpp"
unsigned int MagicCardCount = 0;
unsigned int MonsterCardCount = 0;
int Deck::getMagicCardCount()
{
    return MagicCardCount;
}

int Deck::getMonsterCardCount()
{
    return MonsterCardCount;
}

void Deck::ChangeMonsterCard(unsigned int IDX, const char* MonName, unsigned int AP, unsigned int DP)
{
    MonsterCard NoName(MonName, AP, DP);
    
    if (IDX  >= MonsterCardCount+1)
    {
        IDX = MonsterCardCount;
        this->Monsters[IDX] = NoName;
        MonsterCardCount++;
        if (MonsterCardCount > 20)MonsterCardCount = 20;
    }
    else
    {
        this->Monsters[IDX--] = NoName;
    }
   
    
}

void Deck::ChangeMagicCard(unsigned int IDX2, const char* MagName, const char* Effect, const char* Type)
{
    MagicCard NoMName(MagName, Effect, Type);
    if (IDX2 >= MagicCardCount + 1)
    {
        IDX2 = MagicCardCount;
        this->Magic[IDX2] = NoMName;
        MagicCardCount++;
        if (MagicCardCount > 20)MagicCardCount = 20;
    }
    else
    {
        this->Magic[IDX2--] = NoMName;
    }
    
}

void Deck::ReplaceMonsterCard(unsigned int idx, MonsterCard &Monster)
{
    if (idx >= MonsterCardCount + 1)
    {
        idx = MonsterCardCount;
        this->Monsters[idx] = Monster;
        MonsterCardCount++;
        if (MonsterCardCount > 20)MonsterCardCount = 20;
    }
    else
    {
        this->Monsters[idx--] = Monster;
    }
}

void Deck::ReplaceMagicCard(unsigned int idx2, MagicCard& Magic)
{
    if (idx2 >= MagicCardCount + 1)
    {
        idx2 = MagicCardCount;
        this->Magic[idx2] = Magic;
        MagicCardCount++;
        if (MagicCardCount > 20)MagicCardCount = 20;
    }
    else
    {
        this->Magic[idx2--] = Magic;
    }
}
void Duelist::DuelistChangeMonsterCard(unsigned int id, const char*N, unsigned int A, unsigned int D)
{
    this->DuelistDeck.ChangeMonsterCard(id, N, A, D);
}

void Duelist::DuelistChangeMagicCard(unsigned int id2, const char* Na, const char* EFF, const char* TYY)
{
   this-> DuelistDeck.ChangeMagicCard(id2, Na, EFF, TYY);
}

void Duelist::DuelistReplaceMonsterCard(unsigned int i1, MonsterCard& Mo)
{
    this->DuelistDeck.ReplaceMonsterCard(i1, Mo);
}

void Duelist::DuelistReplaceMagicCard(unsigned int i2, MagicCard& Ma)
{
    this->DuelistDeck.ReplaceMagicCard(i2, Ma);
}