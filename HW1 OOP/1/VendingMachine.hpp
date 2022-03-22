#pragma once
#include"drink.hpp"
class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);
    
    double get_income() const;
    int get_VendingSize()const;

    void PrintVending() const;
    ~VendingMachine();
private:
    Drink* VendingDrinks;
    double VenidngMachineMoney;
    int VendingSize;
};
bool AreDrinksTheSame(const char* One, const char* Two);
