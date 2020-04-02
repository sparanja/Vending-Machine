#include "Milk.h"
Milk::Milk(string branch_name, string description, int quantity, Drink_Size size, float cal, float price) :
	Beverage::Beverage(branch_name, description, quantity, size, cal, price) {

}

void Milk::set_category(string category) {
	Milk::category = category;
}