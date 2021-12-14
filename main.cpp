#include "logic.hpp"

int main()
{
	CoffeeMaker *test1 = new CoffeeMaker();

	test1->FillHopper();
	test1->FillReservoir();
	test1->RequestCoffee(4);

	delete test1;
}