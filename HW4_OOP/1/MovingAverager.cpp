#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string& id, const size_t& windowSize):BaseSub(id),windowSize(windowSize)
{
}

void MovingAverager::signal(const Message& adder)
{
    this->DataContainer.push_back(adder.data);
}

BaseSub* MovingAverager::clone() const
{
    return new MovingAverager(*this);
}

int MovingAverager::read() const
{
    if (DataContainer.size() == 0) return 0;
    int Temp = 0;
    if (this->windowSize >= this->DataContainer.size())
    {
        for (unsigned int i = 0; i < DataContainer.size(); ++i)
        {
            Temp += this->DataContainer[i];
        }
        return Temp / this->DataContainer.size();
    }
    if (this->windowSize < this->DataContainer.size())
    {
        for (unsigned int i = (this->DataContainer.size() - this->windowSize); i < this->DataContainer.size(); ++i)
        {
            Temp += this->DataContainer[i];
        }
        return Temp / this->windowSize;
    }
}
