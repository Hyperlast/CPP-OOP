#include "Repository.hpp"

void Repository::add(BaseSub* adder)
{
    Subscribers.push_back(adder->clone());
}

Repository::Repository(const Repository& RHS)
{
    Subscribers.clear();

    for (unsigned int i = 0; i < RHS.Subscribers.size(); ++i)
    {
        this->add(RHS.Subscribers[i]);
    }
    
}

Repository& Repository::operator=(const Repository& RHS)
{
    if (this != &RHS)
    {
        Subscribers.clear();

        for (unsigned int i = 0; i < RHS.Subscribers.size(); ++i)
        {
            this->add(RHS.Subscribers[i]);
        }
    }
    return *this;
}

BaseSub* Repository::get(std::string id) const
{
    for (unsigned int i = 0; i < Subscribers.size(); ++i)
    {
        if (Subscribers[i]->getID() == id)
        {
            return Subscribers[i];
        }
    }
    return nullptr;
}

Repository::~Repository()
{
    for (unsigned int i = 0; i < Subscribers.size(); ++i)
    {
        delete Subscribers[i];
    }
    Subscribers.clear();
}
