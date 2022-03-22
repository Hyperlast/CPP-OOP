#pragma once


class Counter
{
protected:
	int Point;
	int Step;
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned int step);
	void increment();
	int getTotal()const;
	unsigned getStep()const;
};