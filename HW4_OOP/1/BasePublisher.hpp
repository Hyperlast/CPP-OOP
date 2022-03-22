#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"


class BasePublisher
{
protected:
	std::vector<BaseSub*> subscribers;
	std::vector<int> MessageDatas;
public:
	virtual void subscribe(BaseSub*) = 0;
	virtual void unsubscribe(BaseSub*) = 0;
	virtual void signal(const Message&) = 0;
	~BasePublisher() = default;
};