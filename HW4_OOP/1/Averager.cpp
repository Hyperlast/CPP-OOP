#include "Averager.hpp"

Averager::Averager(const std::string& id) : BaseSub(id)
{
}

void Averager::signal(const Message& add)
{
    this->DataContainer.push_back(add.data);
}

BaseSub* Averager::clone() const
{
    return new Averager(*this);
}

int Averager::read() const
{
    if (DataContainer.size() == 0) return 0;

    int Temp = 0;
    for (unsigned int i = 0; i < DataContainer.size(); ++i)
    {
        Temp += DataContainer[i];
    }
    return Temp / DataContainer.size();
}
