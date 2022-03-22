#include "TeamLead.hpp"


TeamLead::TeamLead(const std::string& name, double salary) : Developer(name)
{
	this->Salary = salary;
	this->Leader = this;
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return this->Devs;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr)
	{
		developer->setSalary(salary);
		developer->setTeamLead(this->Leader);
		this->Devs.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	int temp=-1;
	for (unsigned int i = 0; i < this->Devs.size(); ++i)
	{
		if (Devs[i]->getName() == name)
		{
			temp = i;
		}
	}
	if (temp != -1)
	{
		Devs[temp]->setTeamLead(nullptr);
		Devs.erase(Devs.begin() + temp);
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (unsigned int i = 0; i < this->Devs.size(); ++i)
	{
		double temp = this->Devs[i]->getSalary()+amount;
		this->Devs[i]->setSalary(temp);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (unsigned int i = 0; i < this->Devs.size(); ++i)
	{
		double temp = this->Devs[i]->getSalary() - amount;
		this->Devs[i]->setSalary(temp);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	this->Leave.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	this->Promo.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (unsigned int i = 0; i < this->Leave.size(); ++i)
	{
		bool flag = false;
		int temp=0;
		for (unsigned int j = 0; j < this->Devs.size(); ++j)
		{
			if (Leave[i].getSender() == this->Devs[j]->getName() )
			{
				temp = j;
				flag = true;
			}
		}
		if (flag)
		{
			Devs[temp]->setTeamLead(nullptr);
			removeDeveloperFromTeam(Leave[i].getSender());
			Leave.erase(Leave.begin() + i);
		}
	}
}

void TeamLead::fulfillPromotionRequests()
{
	for (unsigned int i = 0; i < this->Promo.size(); ++i)
	{
		bool flag = false;
		int temp = -1;
		for (unsigned j = 0; j < this->Devs.size(); ++j)
		{
			if (Promo[i].getSender() == this->Devs[j]->getName())
			{
				temp = j;
				flag = true;
			}
		}
		if (flag)
		{
			double amount = Devs[temp]->getSalary()+Promo[i].getAmount();
			Devs[temp]->setSalary(amount);
			Promo.erase(Promo.begin() + i);
		}
	}
}