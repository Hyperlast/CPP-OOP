#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(BaseSub* adder)
{
	if (adder != nullptr)
	{
		this->subscribers.push_back(adder);

		for (unsigned int i = 0; i < MessageDatas.size(); ++i)
		{
			subscribers[subscribers.size()-1]->signal(MessageDatas[i]);
		}
	}
}

void BacklogPublisher::unsubscribe(BaseSub* remover)
{
	for (unsigned int i = 0; i < subscribers.size(); ++i)
	{
		if (this->subscribers[i]->getID() == remover->getID())
		{
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::signal(const Message& Mess)
{
	this->MessageDatas.push_back(Mess.data);
	for (unsigned int i = 0; i < subscribers.size(); ++i)
	{
		subscribers[i]->signal(Mess.data);
	}
}
