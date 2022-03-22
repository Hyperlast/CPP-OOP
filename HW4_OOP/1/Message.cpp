#include "Message.hpp"

Message::Message(int data) : data(data)
{
}

int Message::getData() const
{
	return this->data;
}
