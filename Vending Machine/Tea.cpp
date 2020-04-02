#include "Tea.h"

Tea::Tea(string branch_name, string description, int quantity, Drink_Size size, float cal, float price) :
	Beverage::Beverage(branch_name, description, quantity, size, cal, price) {

}

void Tea::set_category(string category) {
	Tea::category = category;
}