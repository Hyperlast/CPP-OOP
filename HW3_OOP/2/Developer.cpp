#include "Developer.hpp"
#include "TeamLead.hpp"
Developer::Developer(const std::string& name)
{
    this->Name = name;
    this->Salary = 0;
    this->Leader = nullptr;
}

std::string Developer::getName() const
{
    return this->Name;
}

double Developer::getSalary() const
{
    return this->Salary;
}

TeamLead* Developer::getTeamLead() const
{
    return this->Leader;
}

void Developer::setName(std::string name) 
{
    this->Name = name;
}

void Developer::setSalary(double amount)
{
    if (amount >= 0)
    {
        this->Salary = amount;
    }
}

void Developer::setTeamLead(TeamLead* leader)
{
    this->Leader = leader;
}

void Developer::setInitialSalary(double amount)
{
    if (Salary == 0)
    {
        this->Salary = amount;
    }
}

void Developer::sendLeavingRequest()
{
    if (this->Leader != nullptr)
    {
        LeavingRequest R(this->Name);
        Leader->addLeavingRequest(R);
    }
}

void Developer::sendPromotionRequest(double amount)
{
    if (this->Leader != nullptr)
    {
        PromotionRequest R(this->Name, amount);
        Leader->addPromotionRequest(R);
    }
}
