#include <iostream>
#include <vector>

class Hopper
{
private:
	int Beans, BeansMax;

public:
	Hopper() { Beans = 0; BeansMax = 200; }

	int Dispense(int grams)
	{
		if (grams > Beans)
		{
			std::cout << "Hopper: The hopper doesn't have that many beans!" << std::endl;
			return 0;
		}
		Beans -= grams;
		return grams;
	}
	
	void AddBeans(int grams)
	{
		if ((grams + this->Beans) > this->BeansMax)
		{
			std::cout << "Hopper: You added too many beans, so only enough to top off were added." << std::endl;
			this->Beans = 200;
		}
		else
		{
			this->Beans += grams;
			std::cout << "Hopper: There are now " << this->Beans << " grams of beans." << std::endl;
		}
	}
};

class WaterReservoir
{
private:
	float Water, WaterMax;
	int WaterTemp;

public:
	WaterReservoir() { Water = 0.0; WaterMax = 1.0; WaterTemp = 30; }
	
	void ChangeTemp(const int temp)
	{
		std::cout << "Water Reservoir: Water temperature is now " << temp << " degrees Celsius." << std::endl;
		WaterTemp = temp;
	}

	void AddWater(const int liters)
	{
		if (liters > WaterMax)
		{
			std::cout << "Water Reservoir: Only 1 liter of water was added." << std::endl;
			Water = WaterMax;
			this->ChangeTemp(30);
		}
		else
		{
			Water += liters;
			std::cout << "Water Reservoir: There is now " << this->Water << " liter(s) of water in the reservoir." << std::endl;
			this->ChangeTemp(30);
		}
	}

	bool PourWater()
	{
		if (Water < 0.25)
		{
			std::cout << "Water Reservoir: There's not enough water!" << std::endl;
			return false;
		}
		else if (WaterTemp < 100)
		{
			std::cout << "Water Reservoir: The water's not hot enough!" << std::endl;
			return false;
		}
		std::cout << "Water Reservoir: Pouring .25 liters of hot water." << std::endl;
		return true;
	}
};

class HeatSource
{
public:
	HeatSource() {}

	void Heat(WaterReservoir *wr)
	{
		wr->ChangeTemp(100);
        std::cout << "Heat Source: Water heated to 100 degrees celsius." << std::endl;
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
			std::cout << "Grinder: Less than 50 grams of beans in the hopper." << std::endl;
			return false;
		}
		std::cout << "Grinder: 50 grams of beans ground." << std::endl;
		return true;
	}
};

class CupRecepticle
{
public:
	CupRecepticle() {}
	
	bool PourCoffee(Grinder *g, WaterReservoir *wr, Hopper *h)
	{
		if (g->Grind(h) && wr->PourWater())
		{
			std::cout << "Cup recepticle: Coffee made!" << std::endl;
			return true;
		}
		std::cout << "Cup recepticle: Coffee not made." << std::endl;
		return false;
	}
};

class CoffeeMaker
{
public:
	Hopper *h;
	WaterReservoir *wr;
	HeatSource *hs;
	Grinder *g;
	CupRecepticle *cr;
	
	CoffeeMaker()
	{
		h = new Hopper();
		wr = new WaterReservoir();
		hs = new HeatSource();
		g = new Grinder();
		cr = new CupRecepticle();
	}
	
	~CoffeeMaker()
	{
		delete h;
		delete wr;
		delete hs;
		delete g;
		delete cr;
	}
	
	bool RequestCoffee(const int n)
	{
		if (n > 4)
		{
			std::cout << "Coffee Machine: The machine can only make up to 4 cups at a time!" << std::endl;
			return false;
		}

		hs->Heat(wr);

		for (int i = 0; i < n; i++)
		{
			if (cr->PourCoffee(g, wr, h))
			{
				std::cout << "Coffee Machine: " << i+1 << " cup(s) of coffee poured!" << std::endl;
			}
			else
			{
				std::cout << "Coffee Machine: Only " << i << " of the requested " << n << " cup(s) of coffee were poured. Something went wrong!" << std::endl;
				return false;
			}
		}
		std::cout << "Coffee Maker: Enjoy your coffee!" << std::endl;
		return true;
	}

	void FillHopper()
	{
		h->AddBeans(200);
		std::cout << "Coffee Maker: Hopper filled." << std::endl;
	}

	void FillReservoir()
	{
		this->wr->AddWater(1.0);
		std::cout << "Coffee Maker: Water reservoir filled." << std::endl;
	}
};