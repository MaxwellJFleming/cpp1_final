#include <iostream>
#include <vector>

class Hopper
{
private:
	int Beans = 0;
	int BeansMax = 200;

public:
	Hopper() {}
	
	int Dispense(int grams)
	{
		if (grams > Beans)
		{
			std::cout << "The hopper doesn't have that many beans!" << std::endl;
			return 0;
		}
		Beans -= grams;
		return grams;
	}
	
	int AddBeans(int grams)
	{
		if (grams > BeansMax)
		{
			std::cout << "Only 200 grams of beans were added to the hopper." << std::endl;
			Beans = 200;
			return Beans;
		}
		Beans = grams;
	}
};

class WaterReservoir
{
private:
	float Water = 0.0;
	float WaterMax = 1.0;
	float WaterTemp = 30;

public:
	WaterReservoir() {}
	
	void ChangeTemp(int temp)
	{
		std::cout << "Water temperature is now " << temp << " degrees Celsius." << std::endl;
		WaterTemp = temp;
	}

	void AddWater(int liters)
	{
		if (liters > WaterMax)
		{
			std::cout << "Only 1 liter of water was added to the reservoir." << std::endl;
			Water = WaterMax;
		}
		else { Water += liters; }
		std::cout << "There is now " << Water << " liters of water in the reservoir." << std::endl;
	}
};

class HeatSource
{
public:
	HeatSource() {}

	void Heat(WaterReservoir *wr)
	{
		wr->ChangeTemp(100);
	}
};

class Grinder
{
public:
	Grinder() {}

	bool Grind(Hopper *h)
	{
		int amountDispensed = h->Dispense(50);
		if (amountDispensed < 50)
		{
			std::cout << "Not enough beans in the hopper to make a cup." << std::endl;
			return false;
		}
		std::cout << "50 grams of beans ground." << std::endl;
		return true;
	}
};

class CupRecepticle
{
public:
	CupRecepticle() {}
	
	void MakeCoffee()
}

class CoffeeMaker
{
private:
	Hopper *h;
	WaterReservoir *wr;
	HeatSource *hs;
	Grinder *g;
	CupRecepticle *cr;
	
public:
	CoffeeMaker()
	{
		Hopper *h = new Hopper();
		WaterReservoir *wr = new WaterReservoir();
		HeatSource *hs = new HeatSource();
		Grinder *g = new Grinder();
		CupRecepticle *cr = new CupRecepticle();
	}
	
	~CoffeeMaker()
	{
		delete h;
		delete wr;
		delete hs;
		delete g;
		delete cr;
	}
	
	void MakeCups(int n)
	{
		
	}
};

int main() {}