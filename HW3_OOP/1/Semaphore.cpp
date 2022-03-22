#include "Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter()
{
    this->point = 0;
}

Semaphore::Semaphore(bool flag) : LimitedTwowayCounter(0,1,0,1)
{
    this->point = flag;
}

bool Semaphore::isAvailable() const
{
    if (point > 0)
    {
        return true;
    }
    return false;
}

void Semaphore::wait()
{
    if (this->point - this->Step >= this->Min)
    {
        this->point -= Step;
    }
}

void Semaphore::signal()
{
    if (this->point + this->Step <= this->max)
    {
        this->point += Step;
    }
}
