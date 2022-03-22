#include "Counter.hpp"

Counter::Counter()
{
    this->Point = 0;
    this->Step = 1;
}

Counter::Counter(int initial)
{
    this->Point = initial;
    this->Step = 1;
}

Counter::Counter(int initial, unsigned int step)
{
    this->Point = initial;
    this->Step = step;
}

void Counter::increment()
{
    this->Point += this->Step;
}

int Counter::getTotal() const
{
    return this->Point;
}

unsigned int Counter::getStep() const
{
    return this->Step;
}
