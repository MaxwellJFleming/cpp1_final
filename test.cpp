#include "logic.hpp"

int main()
{
    CoffeeMaker *test2 = new CoffeeMaker();

    test2->RequestCoffee(5);
	
    test2->RequestCoffee(1);

	delete test2;
}