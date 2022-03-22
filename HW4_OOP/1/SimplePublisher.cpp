#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(BaseSub* adder)
{
	if (adder != nullptr)
	{
		this->subscribers.push_back(adder);
	}
	
}

void SimplePublisher::unsubscribe(BaseSub* remover)
{
	for (unsigned int i = 0; i < subscribers.size(); ++i)
	{
		if (this->subscribers[i]->getID() == remover->getID())
		{
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::signal(const Message& adder)
{
	MessageDatas.push_back(adder.data);
	for (unsigned int i = 0; i < subscribers.size(); ++i)
	{
		subscribers[i]->signal(adder);
	}
}
