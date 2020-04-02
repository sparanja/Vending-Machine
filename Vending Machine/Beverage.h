#pragma once
#include <string>
#include "SizeEnum.h"

using namespace std;
#pragma once
class Beverage
{

	string brand_name;
	string description;
	int quantity;
	Drink_Size size;
	float calories;
	float price;

public:
	Beverage();
	Beverage(string branch_name, string description, int quantity, Drink_Size size, float cal, float price);

	string get_brand_name();
	void set_brand_name(string brandName);

	string get_description();
	void set_description(string description);

	int get_quantity();
	void set_quantity(int quantity);

	Drink_Size get_size();
	void set_size(Drink_Size size);

	float get_calories();
	void set_calories(float calories);

	float get_price();
	void set_price(float price);
};

