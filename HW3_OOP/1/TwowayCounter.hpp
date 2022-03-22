#pragma once
#include "Counter.hpp"

class TwowayCounter : virtual public Counter
{
public:
	TwowayCounter();
	TwowayCounter(int initial);
	TwowayCounter(int initial, unsigned int step);
	void decrement();
};