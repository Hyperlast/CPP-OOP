#include "drink.hpp"
#include "VendingMachine.hpp"
#include <iostream>

int main()
{
	
	Drink Cola("Coca Cola" , 350, 0.500, 1.20);
	//Cola.get_Drink();
	Drink CZero("Coca Cola Zero", 400, 0.5, 1.40);
	//CZero.get_Drink();
	//Drink Fanta("Fanta", 120, 0.5, 1.20);//Name could be nullptr
	//Fanta.get_Drink();

	VendingMachine R;
	R.add_drink(CZero);
	R.add_drink(Cola);
	R.add_drink(Cola);
	R.PrintVending();
	std::cout<<"Income-> "<< R.get_income()<<std::endl;
	R.buy_drink("Coca Cola Zero", 0.90);
	R.buy_drink("Coca Cola Zero", 0.90);
	R.buy_drink("Coca Cola Zero" , 2.90);
	R.PrintVending();
	std::cout << "Income-> " << R.get_income() << std::endl;
	return 0;
}