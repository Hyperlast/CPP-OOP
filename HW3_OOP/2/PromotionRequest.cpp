#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest()
{
    this->Quantity = 0;
}

PromotionRequest::PromotionRequest(const std::string& sender, double amount)
{
    this->Message = "I want a raise!";
    this->Sender = sender;
    this->Quantity = amount;
    this->Counter += 1;
    this->ID = Counter;
}

double PromotionRequest::getAmount() const
{
    return this->Quantity;
}
