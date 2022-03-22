#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter
{
protected:
	int point;
public:
	Semaphore();
	Semaphore(bool);

	bool isAvailable()const;
	void wait();
	void signal();
};