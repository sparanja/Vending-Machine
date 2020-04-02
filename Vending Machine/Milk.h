#pragma once
#include "Beverage.h"
class Milk :
	public Beverage
{
	string category;
public:
	Milk(string branch_name, string description, int quantity, Drink_Size size, float cal, float price);
	void set_category(string category);
};

