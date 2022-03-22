#pragma once
#include"Message.hpp"
#include <string>
#include <vector>

class BaseSub
{
protected:
	std::vector<int> DataContainer;
public:
	const std::string id;
	std::string getID()const { return this->id; }
	BaseSub(const std::string& id) :id(id) {}
	virtual void signal(const Message&)=0;
	virtual int read()const = 0;
	virtual BaseSub* clone()const=0;
	virtual ~BaseSub() = default;
};