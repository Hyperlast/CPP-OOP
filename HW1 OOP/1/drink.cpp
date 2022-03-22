#include "drink.hpp"
#include <iostream>
#include <cstring>

int my_strlen(const char* str)
{
    unsigned int i = 0;
    for (; str[i] != '\0'; ++i);
    return i;
}
Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
    delete[] Name;
    if (init_name == nullptr)
    {
        Name = new char[1];
        Name[0] = '\0';
    }
    else
    {
        Name = new char[my_strlen(init_name) + 1];
        strcpy_s(Name, my_strlen(init_name) + 1, init_name);
    }
    this->Calories = init_calories;
    this->Quantity = init_quantity;
    this->Price = init_price;
}

Drink::Drink(const Drink& Rand)
{
    if (Rand.get_name() == nullptr)
    {
        Name = new char[1];
        Name[0] = '\0';
    }
    else
    {
        Name = new char[my_strlen(Rand.Name) + 1];
        strcpy_s(Name, my_strlen(Rand.Name) + 1, Rand.Name);
    }
    this->Calories = Rand.Calories;
    this->Price = Rand.Price;
    this->Quantity = Rand.Quantity;
}

Drink& Drink::operator=(const Drink& rhs)
{
    if (this != &rhs)
    {
        delete[] Name;
        Name = new char[my_strlen(rhs.Name) + 1];
        strcpy_s(Name, my_strlen(rhs.Name)+1, rhs.Name);
        this->Calories = rhs.Calories;
        this->Price = rhs.Price;
        this->Quantity = rhs.Quantity;
    }
    return *this;

}

Drink::Drink()
{
    Name = new char[1];
    Name[0] = '\0';
    this->Calories = 0;
    this->Quantity = 0;
    this->Price = 0;
}

const char* Drink::get_name() const
{
    return this->Name;
}

int Drink::get_calories() const
{
    return this->Calories;
}

double Drink::get_quantity() const
{
    return this->Quantity;
}

double Drink::get_price() const
{
    return this->Price;
}

void Drink::set_name(const char* new_name)
{
    delete[] Name;
    Name = new char[my_strlen(new_name) + 1];
    strcpy_s(Name, my_strlen(new_name)+1,new_name);
}

void Drink::set_calories(int cal)
{
    this->Calories=cal;
}

void Drink::set_quantity(double QQ)
{
    this->Quantity = QQ;
}

void Drink::set_price(double PP)
{
    this->Price = PP;
}

void Drink::get_Drink()
{
    std::cout << "The drink's Name is: " << this->Name << std::endl
        << "It has " << this->Calories << " much calories and it's volume is " << this->Quantity
        << std::endl<<"It costs "<<this->Price<<std::endl;
}

Drink::~Drink()
{
    delete[] Name;
}

