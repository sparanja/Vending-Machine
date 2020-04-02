#include "Fruit.h"

Fruit::Fruit(string branch_name, string description, int quantity, Drink_Size size, float cal, float price) :
	Beverage::Beverage(branch_name, description, quantity, size, cal, price) {

}

void Fruit::set_category(string category) {
	Fruit::category = category;
}