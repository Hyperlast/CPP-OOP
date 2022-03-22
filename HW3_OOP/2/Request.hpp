#pragma once 
#include <string>
#include <iostream>

class Request
{
protected:
	std::string Message;
	std::string Sender;
	unsigned int ID;
public:
	static unsigned int Counter;
	Request();
	Request(const std::string& message,const std::string& sender);

	std::string getMessage()const;
	std::string getSender()const; 
	int getCount()const;
	int getID()const;

};