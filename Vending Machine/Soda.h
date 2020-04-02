#pragma once
#include "Beverage.h"
class Soda :
	public Beverage
{
	string category;
public:
	Soda();
	Soda(string brand_name, string description, int quantity, Drink_Size size, float cal, float price);
	void set_category(string category);
};

