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
#include "Cards.hpp"

unsigned int my_strlen(const char* s)
{
    unsigned int i = 0;
    for (; s[i] != '\0'; ++i);

    return i;
}

char* copyString(const char* str)
{
    int n = my_strlen(str);
    char* Copy = new char[n + 1];
    
    for (unsigned int i = 0; str[i] != '\0'; ++i)
    {
        Copy[i] = str[i];
    }
    Copy[n] = '\0';
    return Copy;
}

void MonsterCard::setMonsterName(const char* Name)
{
    if (my_strlen(Name) > 25)
    {
        this->MonsterName = nullptr;
    }
    else
    {
        this->MonsterName = copyString(Name);
    }
}

void MonsterCard::setAttackPoints(const unsigned int AP)
{
    this->AttackPoints = AP;
}

void MonsterCard::setDefensePoints(const unsigned int DP)
{
    this->DefensePoints = DP;
}

const char* MonsterCard::getMonsterName() const
{
    return this->MonsterName;
}

const int MonsterCard::getAttackPoints() const
{
    return this->AttackPoints;
}

const int MonsterCard::getDefensePoints() const
{
    return this->DefensePoints;
}

MonsterCard::MonsterCard()
{
    this->MonsterName = nullptr;
    this->AttackPoints = 0;
    this->DefensePoints = 0;
}

MonsterCard::MonsterCard(const char* Name, unsigned int Attack, unsigned int Defense)
{
    setMonsterName(Name);
    this->AttackPoints = Attack;
    this->DefensePoints = Defense;
}

bool MagicCard::IsTypeRight(const char* Type)
{
    //“trap”, “buff”, “spell”
    char T[] = "Trap";
    char B[] = "Buff";
    char S[] = "Spell";
    bool IsRight = false;
    int CounterB=0;
    int CounterT = 0;
    int CounterS = 0;
    for (unsigned int i = 0; Type[i] != '\0'; ++i)
    {
        if (Type[i] == T[i])
        {
            CounterT++;
        }
        if (Type[i] == B[i])
        {
            CounterB++;
        }
        if (Type[i] == S[i])
        {
            CounterS++;
        }
    }
    if (CounterT == 4||CounterB==4||CounterS==5)
    {
        return true;
    }
       return false;
}

void MagicCard::setMagicName(const char* MName)
{
    if (my_strlen(MName) > 25)
    {
        this->MagicName = nullptr;
    }
    else
    {
        this->MagicName = copyString(MName);
    }
}

void MagicCard::setEffect(const char* Ef)
{
    if (my_strlen(Ef) > 100)
    {
        this->Effect = nullptr;
    }
    else
    {
        this->Effect = copyString(Ef);
    }
}

void MagicCard::setType(const char*Ty)
{
    if (!IsTypeRight(Ty)) this->Type = nullptr;

    else 
    {
        this->Type = copyString(Ty);
    }
}

const char* MagicCard::getMagicName() const
{
    return this->MagicName;
}

const char* MagicCard::getEffect() const
{
    return this->Effect;
}

const char* MagicCard::getType() const
{
    return this->Type;
}

MagicCard::MagicCard()
{
    this->MagicName = nullptr;
    this->Effect = nullptr;
    this->Type = nullptr;
}

MagicCard::MagicCard(const char* MName, const char* Ef, const char*Ty)
{
    setMagicName(MName);
    setEffect(Ef);
    setType(Ty);
}


