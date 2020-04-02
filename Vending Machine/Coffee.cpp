#include "Coffee.h"

//Call the Super class constructor :- Beverage
Coffee::Coffee(string branch_name, string description, int quantity, Drink_Size size, float cal, float price) :
	Beverage::Beverage(branch_name, description, quantity, size, cal, price) {

}

void Coffee::set_category(string category) {
	Coffee::category = category;
}