#pragma once
#include "Beverage.h"
class Fruit :
	public Beverage
{
	string category;
public:
	Fruit(string branch_name, string description, int quantity, Drink_Size size, float cal, float price);
	void set_category(string category);
};

