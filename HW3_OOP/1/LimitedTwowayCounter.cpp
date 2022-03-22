#include "LimitedTwowayCounter.hpp"


LimitedTwowayCounter::LimitedTwowayCounter() : LimitedCounter()
{
    this->Min = 0;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min) : LimitedCounter()
{
    this->Min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) : LimitedCounter(max)
{
    this->Min = min;
 
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) : LimitedCounter(max,initial)
{
    this->Min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step) : LimitedCounter(max,initial,step)
{
    this->Min = min;
}

void LimitedTwowayCounter::decrement()
{
    if (this->Point - this->Step >= this->Min)
    {
        this->Point -= Step;
    }
}

int LimitedTwowayCounter::getMin() const
{
    return this->Min;
}
