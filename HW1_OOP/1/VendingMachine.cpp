#include "VendingMachine.hpp"
#include <iostream>

VendingMachine::VendingMachine()
{
    VendingDrinks = new Drink[1];
    VendingDrinks[0] = Drink();
    this->VendingSize = 0;
    this->VenidngMachineMoney = 0;
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
    this->VendingSize = from.get_VendingSize();
    VendingDrinks = new Drink[VendingSize];
    this->VenidngMachineMoney = from.get_income();
    for ( int i = 0; i < this->VendingSize; ++i)
    {
        VendingDrinks[i] = from.VendingDrinks[i];
    }
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
    if (this != &from)
    {
        delete[] VendingDrinks;
        this->VendingSize = from.get_VendingSize();
        VendingDrinks = new Drink[VendingSize];
        this->VenidngMachineMoney = from.get_income();

        for ( int i = 0; i < this->VendingSize; ++i)
        {
            VendingDrinks[i] = from.VendingDrinks[i];
        }
    }
    return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
    for (int i = 0; i < this->VendingSize; ++i)
    {
        if (AreDrinksTheSame(to_add.get_name(),VendingDrinks[i].get_name()))
        {
            return false;
        }
    }
    Drink* Temp = new Drink[VendingSize + 1];
    for (int i = 0; i < VendingSize; ++i)
    {
        Temp[i] = VendingDrinks[i];
    }
    delete[] VendingDrinks;
    VendingDrinks = new Drink[VendingSize + 1];
    for (int i = 0; i < VendingSize; ++i)
    {
         VendingDrinks[i] = Temp[i];
    }
    delete[] Temp;
    VendingDrinks[VendingSize] = to_add;
    this->VendingSize++;
 
    return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
    for (int i = 0; i < this->VendingSize; ++i)
    {
        if (AreDrinksTheSame(drink_name, VendingDrinks[i].get_name()) && money >= VendingDrinks[i].get_price())
        {
            int DrinkIDX=i;
            for(int j=i;j<VendingSize-1;++j)
            {
                VendingDrinks[i] = Drink();
                VendingDrinks[i] = VendingDrinks[i + 1];
            }
            VendingDrinks[VendingSize-1]=Drink();
            this->VenidngMachineMoney += money;
            VendingSize--;
            return 0;
        }
        if (AreDrinksTheSame(drink_name, VendingDrinks[i].get_name()) && money < VendingDrinks[i].get_price())
        {
            this->VenidngMachineMoney += money;
            return 1;
        }
    }
    return 2;
}

double VendingMachine::get_income() const
{
    return this->VenidngMachineMoney;
}

int VendingMachine::get_VendingSize() const
{
    return VendingSize;
}

void VendingMachine::PrintVending() const
{
    for (int i = 0; i < this->VendingSize; ++i)
    {
        std::cout << "No_" << i + 1 << " Drink" << std::endl;
        std::cout<<VendingDrinks[i].get_name() << std::endl;
        std::cout << VendingDrinks[i].get_calories() << std::endl;
        std::cout << VendingDrinks[i].get_quantity() << std::endl;
        std::cout << VendingDrinks[i].get_price() << std::endl;
    }
}

VendingMachine::~VendingMachine()
{
    delete[] VendingDrinks;
}

bool AreDrinksTheSame(const char* One, const char* Two)
{
    if (my_strlen(One) != my_strlen(Two))
    {
        return false;
    }
    for (int i = 0; i < my_strlen(One); ++i)
    {
        if (One[i] != Two[i])
        {
            return false;
        }
    }
    return true;
}