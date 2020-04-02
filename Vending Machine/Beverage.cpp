#include "Beverage.h"

Beverage::Beverage() {
	Beverage::brand_name = "";
	Beverage::description = "";
	Beverage::quantity = 0;
	Beverage::size = Small;
	Beverage::calories = 0.0;
	Beverage::price = 0;
}

Beverage::Beverage(string brand_name, string description, int quantity, Drink_Size size, float calories, float price) {
	Beverage::brand_name = brand_name;
	Beverage::description = description;
	Beverage::quantity = quantity;
	Beverage::size = size;
	Beverage::calories = calories;
	Beverage::price = price;
}

string Beverage :: get_brand_name() {
	return Beverage::brand_name;
}
void Beverage :: set_brand_name(string brandName) {
	Beverage::brand_name = brandName;
}

string Beverage::get_description() {
	return Beverage::description;
}
void Beverage::set_description(string description) {
	Beverage::description = description;
}

int Beverage::get_quantity() {
	return Beverage::quantity;
}
void Beverage::set_quantity(int quantity) {
	 Beverage::quantity = quantity;
}

Drink_Size Beverage::get_size(){
	return Beverage::size;
}
void Beverage::set_size(Drink_Size size) {
	Beverage::size = size;
}

float Beverage::get_calories() {
	return Beverage::calories;
}
void Beverage::set_calories(float calories) {
	Beverage::calories = calories;
}

float Beverage::get_price() {
	return Beverage::price;
}
void Beverage::set_price(float price) {
	Beverage::price = price;
}