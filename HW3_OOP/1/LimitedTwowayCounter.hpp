#pragma once
#include "Counter.hpp"
#include"LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter :  public LimitedCounter,  public TwowayCounter
{
protected:
	int Min;
public:
	LimitedTwowayCounter();
	LimitedTwowayCounter(int min);
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned int step);
		
	void decrement();
	int getMin()const;

};