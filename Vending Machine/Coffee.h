#pragma once
#include "Beverage.h"
class Coffee :
	public Beverage
{
string category;
public:
	Coffee(string branch_name, string description, int quantity, Drink_Size size, float cal, float price);
	void set_category(string category);
};

