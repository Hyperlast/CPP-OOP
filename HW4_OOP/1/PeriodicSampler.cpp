#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string& id,const size_t& period) : BaseSub(id),period(period),PeriodCheck(0)
{
}

void PeriodicSampler::signal(const Message& add)
{
    this->DataContainer.push_back(add.data);
}

BaseSub* PeriodicSampler::clone() const
{
    return new PeriodicSampler(*this);
}

int PeriodicSampler::read()const
{
    if (DataContainer.size() == 0) return 0;
    int Temp = 0;
    for (unsigned int i = 0; i < DataContainer.size(); ++i)
    {
        if (i % period == 0)
        {
            Temp = DataContainer[i];
        }
    }

    return Temp;
}
