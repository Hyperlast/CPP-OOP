#pragma once
#include<string>
class Debug {
public:
	virtual std::string debug_print()const = 0;
	virtual ~Debug() = default;
};