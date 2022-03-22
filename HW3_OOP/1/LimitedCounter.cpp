#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter()
{
    this->Point = 0;
    this->max = 0;
    this->Step = 1;
};


LimitedCounter::LimitedCounter(int max)
{
    this->Point = 0;
    this->max = max;
    this->Step = 1;
}

LimitedCounter::LimitedCounter(int max, int initial) 
{
    this->Point = initial;
    this->max = max;
    this->Step = 1;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned int step)
{
    this->max = max;
    this->Point = initial;
    this->Step = step;
}

void LimitedCounter::increment()
{
    if (this->Point + this->Step <= this->max)
    {
        this->Point += this->Step;
    }
}

int LimitedCounter::getMax() const
{
    return this->max;
}
