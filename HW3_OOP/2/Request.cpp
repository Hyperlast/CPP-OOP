#include "Request.hpp"

unsigned Request::Counter = 0;

Request::Request()
{
    this->Message = "";
    this->Sender = "";
    this->ID = 0;
}

Request::Request(const std::string& message, const std::string& sender)
{
    this->Message = message;
    this->Sender = sender;
    this->Counter += 1;
    this->ID = Counter;
}

std::string Request::getMessage() const
{
    return this->Message;
}

std::string Request::getSender() const
{
    return this->Sender;
}

int Request::getCount() const
{
    return this->Counter;
}

int Request::getID() const
{
    return this->ID;
}
