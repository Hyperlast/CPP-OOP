#pragma once 
#include "Request.hpp"




class PromotionRequest : public Request
{
protected:
	double Quantity;
public:
	PromotionRequest();
	PromotionRequest(const std::string& sender,double amount);
	double getAmount()const;
};