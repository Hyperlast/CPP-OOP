#pragma once
#include "Request.hpp"
#include "PromotionRequest.hpp"
#include "LeavingRequest.hpp"

class TeamLead;

class Developer 
{
protected:
	std::string Name;
	double Salary;
	TeamLead* Leader;
public:
	Developer(const std::string& name);

	std::string getName()const;
	double getSalary()const;
	TeamLead* getTeamLead()const;
	
	void setName(std::string);
	void setSalary(double amount);
	void setTeamLead(TeamLead*);
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
};