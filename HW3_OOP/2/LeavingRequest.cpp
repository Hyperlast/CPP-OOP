#include "LeavingRequest.hpp"


LeavingRequest::LeavingRequest(const std::string& sender)
{
	this->Sender = sender;
	this->Message = "I want to leave!";
	this->Counter += 1;
	this->ID = this->Counter;
}
