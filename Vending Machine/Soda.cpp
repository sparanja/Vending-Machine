#include "Soda.h"

Soda::Soda() {

}
//Call the Super class constructor :- Beverage
Soda::Soda(string brand_name, string description, int quantity, Drink_Size size, float cal, float price):
	Beverage::Beverage(brand_name, description, quantity, size, cal, price){

	}

void Soda::set_category(string category) {
	Soda::category = category;
}