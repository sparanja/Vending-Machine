/*=========================================
; Title:  Sumanth Paranjape
; Author: sparanj2@asu.edu
; Date:   1 Apr 2020
; ========================================== */

#include "ResourceManager.h"
#include <iostream>
#include <sstream>


using namespace std;

ResourceManager* ResourceManager::r_instance = NULL;

ResourceManager::ResourceManager() {

}

/*
	Singleton Pattern, only one instance can be created.
*/
ResourceManager* ResourceManager::getInstance() {
	if (!ResourceManager::r_instance)
		ResourceManager::r_instance = new ResourceManager();
	return r_instance;
}

/*
	Initializes the machine with data
	Six Beverage Types Namely: Soda, Coffee, Tea, Fruit, Milk,
	All inherited from Beverage base class.
*/
void ResourceManager::fillMachine() {
	vector<Drink_Size> drink_Size({ Small, Medium, Large });
    ResourceManager::beverageTypes = { "Soda", "Coffee", "Tea", "Fruit", "Milk" };
	ResourceManager::credits = 20;

	//Soda Items
	vector<string> brand_labels({"Coca-Cola","Pepsi","Dr_Pepper", "Sprite"});
	string beverage = "soda";
	fillItems(brand_labels, drink_Size, beverage);

	//Coffee Items
	brand_labels.clear(); 
	brand_labels = { "Starbucks", "Dunkin_Donuts", "Dutch_Bros", "Nescafe"}; beverage = "coffee";
	fillItems(brand_labels, drink_Size, beverage);

	//Tea Items
	brand_labels.clear();
	brand_labels = { "Lipton", "Brisk", "Fuze" }; beverage = "tea";
	fillItems(brand_labels, drink_Size, beverage);

	//Fruit Items
	brand_labels.clear();
	brand_labels = { "Tropicana", "Minute_Maid", "Del_Monte", "Langer's" }; beverage = "fruit";
	fillItems(brand_labels, drink_Size, beverage);

	//Milk Items
	brand_labels.clear();
	brand_labels = { "Baskin_Robins", "Crusha", "Shmoo", "Frijj" }; beverage = "milk";
	fillItems(brand_labels, drink_Size, beverage);
}


/*
	Creates objects namely Soda, Coffee, Tea, Fruit or Milk based on the beverage passed.
	Parameters set in the constructor: branch_name,  description,  quantity,  size,  calories, price
*/
void ResourceManager::fillItems(vector<string>& brand_labels, vector<Drink_Size> drink_Size, string beverage) {
	try {
		for (string label : brand_labels) {
			for (Drink_Size size : drink_Size) {
				if (beverage == "soda") {
					//      brand_name, description,quantity,size,    calories               ,  price
					Soda soda(label, "Soda:" + label, 5, size, size * getRandom(140, 160), size * getRandom(1, 2));
					availableBeverages.push_back(soda);
				}
				else if (beverage == "coffee") {
					Coffee coffee(label, "Coffee:" + label, 5, size, size * getRandom(70, 90), size * getRandom(2, 3));
					availableBeverages.push_back(coffee);
				}
				else if (beverage == "tea") {
					Tea tea(label, "Tea:" + label, 5, size, size * getRandom(70, 90), size * getRandom(2, 3));
					availableBeverages.push_back(tea);
				}
				else if (beverage == "fruit") {
					Fruit fruit(label, "Fruit:" + label, 5, size, size * getRandom(90, 110), size * getRandom(2, 3));
					availableBeverages.push_back(fruit);
				}
				else if (beverage == "milk") {
					Milk milk(label, "Milk:" + label, 5, size, size * getRandom(70, 90), size * getRandom(2, 3));
					availableBeverages.push_back(milk);
				}
			}
		}
	}
	catch (exception e) {
		cout << "Exception occured while parsing the information.Please check and re-enter:"
			"(Type) is case-sensistive." << e.what() << endl;
	}
}

void ResourceManager::printItems() {

	if (availableBeverages.size() == 0)
		cout << "There are 0 items in the store!" << endl;

	for (Beverage bev : availableBeverages) {
		std::cout << "BRAND_NAME | DESCRIPTION | QUANTITY | SIZE | CALORIES | PRICE" << endl;
		std::cout << bev.get_brand_name() << " | " << bev.get_description() << " | " << bev.get_quantity() << " | "
			<< bev.get_size() << " | " << bev.get_calories() << " | " << bev.get_price() << endl;
	}
}

void ResourceManager::printItem(Beverage bev) {

	std::cout << "BRAND_NAME | DESCRIPTION | QUANTITY | SIZE | CALORIES | PRICE" << endl;
	std::cout << bev.get_brand_name() << " | " << bev.get_description() << " | " << bev.get_quantity() << " | "
			<< bev.get_size() << " | " << bev.get_calories() << " | " << bev.get_price() << endl;
}

void ResourceManager::getByID()
{
	try
	{
		string params;
		cout << "::::::::::::::::::::::::::::::::::\n";
		cout << "To view details of an item, enter ID in the format below:\n";
		cout << "BRAND_NAME  SIZE(1-3)" << endl;
		cin >> ws;

		getline(cin, params, '\n');
		vector<string> paramList = ResourceManager::splitString(params, ' ');
		if (paramList.size() < 2) {
			cout << "ERROR: Issue with parsing, please check if a parameter is missing." << endl;
			return;
		}

		string dummy = "";
		Drink_Size drinkSize = ResourceManager::getDrinkSize(stoi(paramList[1]));
		Beverage beverage(paramList[0], dummy, 1, drinkSize, 0, 0);
		int index = ResourceManager::exists(beverage);
		if (index != -1) {
			cout << "SUCCESS:: This requested item was found:" << endl;
			printItem(availableBeverages[index]);
		}
		else {
			cout << "ERROR:: The requested item was not found!" << endl;
		}
	}
	catch (const std::exception&)
	{

	}
	
}

void ResourceManager::deleteAll()
{
	availableBeverages.clear();
	cout << "Successfully deleted all contents in the datastore!" << endl;
}

/*
	Displays all drinks by thier brand name and available sizes.
*/
void ResourceManager::viewItemSet()
{
	try {
		for (Beverage beverage : availableBeverages) {
			if (ResourceManager::itemSet.find(beverage.get_brand_name()) == itemSet.end()) {
				itemSet.insert(beverage.get_description());
			}
		}
		cout << ":::::::::::::::::::::::::::::::::::::::::::::" << endl;
		cout << "List of available items" << endl;
		std::unordered_set<string>::iterator itr;
		for (itr = itemSet.begin(); itr != itemSet.end(); itr++) {

			cout << "Item: " << (*itr) << " Size (Small-1, Medium-2, Large-3)" << endl;
		}
	}
	catch (exception e) {
		cout << "Exception occured while parsing the values" << e.what();
	}
}

/*
	Sets data into parameter array to be fed to Create/Update functions.
*/
vector<string> ResourceManager::converToParams(Beverage beverage,string type) {
	vector<string> updatedParams;
	updatedParams.push_back(type);
	updatedParams.push_back(beverage.get_brand_name()); updatedParams.push_back(beverage.get_description());

	updatedParams.push_back(to_string(beverage.get_quantity()-1)); 
	updatedParams.push_back(to_string(beverage.get_size()));
	updatedParams.push_back(to_string(beverage.get_calories())); updatedParams.push_back(to_string(beverage.get_price()));

	return updatedParams;
}

/*
	Functionality to buy items from the store and update user credit and datastore.
*/
void ResourceManager::buyItems()
{
	try {
		string params;
		cout << "::::::::::::::::::::::::::::::::::\n";
		cout << "To buy an item, enter single space-separated parameters, as shown below:\n";
		cout << "Type(Soda, Coffee, Tea, Fruit, Milk) BRAND_NAME  SIZE(1-3)" << endl;
		cin >> ws;

		getline(cin, params, '\n');
		vector<string> paramList = ResourceManager::splitString(params, ' ');
		if (paramList.size() < 3) {
			cout << "ERROR: Issue with parsing, please check if a parameter is missing.";
			return;
		}

		string dummy = "";
		Drink_Size drinkSize = ResourceManager::getDrinkSize(stoi(paramList[2]));
		Beverage beverage(paramList[1], dummy, 1, drinkSize, 0, 0);
		int index = ResourceManager::exists(beverage);
		if (index != -1) {
			if (ResourceManager::credits < availableBeverages[index].get_price()) {
				cout << "You do not possess suffiecient balance to make this transaction!. Try again.";
				return;
			}
			string type = paramList[0];
			Beverage savedState = availableBeverages[index];
			paramList.clear();
			if (availableBeverages[index].get_quantity() == 0) {
				cout << "This item is out of stock in the store. Please try another item!";
				return;
			}
			paramList = ResourceManager::converToParams(availableBeverages[index], type);
			update(paramList, true);
			ResourceManager::credits = ResourceManager::credits - (int)savedState.get_price();
			cout << "Remaining Credit:" << ResourceManager::credits;
		}
		else {
			cout << "The items does not exist in the store. Select View Item Sets to list available items" << endl;
			return;
		}
	}
	catch (exception e) {
		cout << "Exception occured while parsing the values" << e.what();
	}
}

void ResourceManager::rechargeAccount()
{
	int recharge;
	cout << "Your current account balance is: "<< ResourceManager::credits <<endl;
	cout << "Enter amount to recharge: " << endl;
	cin >> recharge;

	if (ResourceManager::credits + recharge > 100) {
		cout << "FAILED: Cannot recharge above the limit (100$), try again." << endl;
		return;
	}
	else
		ResourceManager::credits += recharge;
	cout << "Recharge Successful! Remaining:"<< ResourceManager::credits <<endl;
}

/*
	Get Random number between min and max values.
*/
int ResourceManager::getRandom(int min, int max) {
	int outPut = rand() % ((max - min) + 1) + min;
	return outPut;
}

/*
	Deletion from the in-memory cache datastore.
*/
vector<Beverage> swap_and_remove(vector<Beverage>& beverage, int index) {
	int listLen = beverage.size();
	Beverage temp = beverage[index];
	beverage[index] = beverage[listLen - 1];
	beverage[listLen - 1] = temp;
	beverage.erase(beverage.begin()+(listLen-1));
	return beverage;
}

//We shall use the concept of Generics here. It is feasible in this project.
int ResourceManager::exists(Beverage created)
{
	int index = 0;
	for (Beverage beverage : availableBeverages) {
		if (beverage.get_brand_name() == created.get_brand_name() &&
			beverage.get_size() == created.get_size()) {
				return index;
		}
		index++;
	}
	return -1;
}

/*
	Validation function for objects
*/
bool ResourceManager::isValid(Drink_Size size, int calories, int price, int quantity) {
	bool valid = true;
	if (calories < 70 || calories > 480)
		valid = false;
	else if (size < 1 || size > 3)
		valid = false;
	else if (price < 0 || price > 27)
		valid = false;
	else if (quantity < 0 || quantity > 5)
		valid = false;

	return valid;
}
 
/*
	Common method for create and update controlled by isUpdate flag.
*/
void ResourceManager::update(vector<string>& paramList, bool isUpdate) {
	try {
		Drink_Size size = getDrinkSize(stoi(paramList[4]));
		int calories = stoi(paramList[5]);
		int price = stoi(paramList[6]);
		int quantity = stoi(paramList[3]);
		Beverage beverage;

		if (!isUpdate) {
			calories = size * calories;
			price = size * price;
		}

		if (!ResourceManager::isValid(size, calories, price, quantity)) {
			cout << "ERROR:: The entered parameters are invalid or out of range" << endl;
			return;
		}

		if (paramList[0] == "Soda") {
			Soda soda(paramList[1], paramList[2], quantity, size, calories, price);
			beverage = soda;
		}
		else if (paramList[0] == "Coffee") {
			Coffee coffee(paramList[1], paramList[2], quantity, size,calories, price);
			beverage = coffee;
		}
		else if (paramList[0] == "Tea") {
			Tea tea(paramList[1], paramList[2], quantity, size, calories, price);
			beverage = tea;
		}
		else if (paramList[0] == "Fruit") {
			Fruit fruit(paramList[1], paramList[2], quantity, size, calories, price);
			beverage = fruit;
		}
		else if (paramList[0] == "Milk") {
			Milk milk(paramList[1], paramList[2], quantity, size, calories, price);
			beverage = milk;
		}
		else
		{
			cout << "ERROR:: Invalid (Type) entered. Please check and re-enter." << endl;
			return;
		}

		//If already exists in store throw error and return.
		int index = ResourceManager::exists(beverage);
		if (isUpdate) {
			if (index != -1) {
				availableBeverages = swap_and_remove(availableBeverages, index);
				availableBeverages.push_back(beverage);
				cout << "SUCCESS:: This item was successfully updated in the store!";
			}
			else {
				cout << "ERROR:: Request item does not exist in store. Please create it.";
				return;
			}
		}
		else {
			if (index != -1) {
				cout << "ERROR:: This item already exits in the store.";
				return;
			}
			else
			{
				availableBeverages.push_back(beverage);
				cout << "SUCCESS:: This item was successfully inserted in the store!";
			}
		}

		//printItems();
		return;
	}
	catch (exception e) {
		cout << "Exception occured while parsing the information.Please check and re-enter:"
			 	"(Type) is case-sensistive."<< e.what() << endl;
	} 
}

//Overridden method for update to be called from main.
void ResourceManager::update() {
	create(true);
}

/*
	Create method main control code, calls the update function with isUpdate false.
*/
void ResourceManager::create(bool isUpdate) {
	try{ 
		string params;
		cout << "::::::::::::::::::::::::::::::::::\n";
		cout << "To create/update an item, enter 1 space-separated parameters, as shown below:\n";
		cout << "TYPE(Soda|Coffee|Tea|Fruit|Milk) BRAND_NAME DESCRIPTION(eg:This_is_a_good_description)"
				" QUANTITY(1-5) SIZE(1-3) CALORIES(70-160) PRICE(1-9)" << endl;
		cin >> ws;

		getline(cin, params, '\n');
		vector<string> paramList = ResourceManager::splitString(params, ' ');
		if (paramList.size() < 7) {
			cout << "ERROR: Issue with parsing, please check if a parameter is missing." << endl;
			return;
		}
		update(paramList, isUpdate);
	}
	catch (exception e) {
		cout << "Exception occured while parsing the information.Please check and re-enter:"
				"(Type) is case-sensistive." << e.what() << endl;
	}
}

/*
	Delete objects
*/
void ResourceManager::delete_item() {
	try
	{
		string params;
		cout << "::::::::::::::::::::::::::::::::::\n";
		cout << "To delete an item, enter 1 space-separated parameters, as shown below:\n";
		cout << "BRAND_NAME  SIZE(1-3)" << endl;
		cin >> ws;

		getline(cin, params, '\n');
		vector<string> paramList = ResourceManager::splitString(params, ' ');
		if (paramList.size() < 2) {
			cout << "ERROR: Issue with parsing, please check if a parameter is missing." << endl;
			return;
		}

		string dummy = "";
		Drink_Size drinkSize = ResourceManager::getDrinkSize(stoi(paramList[1]));
		Beverage beverage(paramList[0], dummy, 1, drinkSize, 0, 0);
		int index = ResourceManager::exists(beverage);
		if (index != -1) {
			availableBeverages = swap_and_remove(availableBeverages, index);
			cout << "SUCCESS:: This item was successfully deleted from the store!" << endl;
		}
		else {
			cout << "ERROR:: Item to delete was not found!" << endl;
		}
	}
	catch (exception e)
	{
		cout << "Exception occured while parsing the information.Please check and re-enter:"
			"(Type) is case-sensistive." << e.what() << endl;
	}
	
}

/*
	Reinitialize the Vending machine with initial values.
*/
void ResourceManager::reset() {
	availableBeverages.clear();
	fillMachine();
	cout << "Vending Machine reset successfully" << endl;
}

/*
	Split string helper function
*/
vector<string> ResourceManager::splitString(string str, char delim) {
	vector<string> paramList;

	try {
		std::stringstream ss(str);
		std::string token;
		while (std::getline(ss, token, delim)) {
			paramList.push_back(token);
		}
	}
	catch (exception e) {
		cout << "Exception occured while parsing the information.Please check and re-enter:"
			"(Type) is case-sensistive." << e.what() << endl;
	}
	
	return paramList;
}

/*
	Maps int to Drink_Size enum.
*/
Drink_Size ResourceManager::getDrinkSize(int val) {
	return (val == 1) ? Small : ((val == 2) ? Medium : ((val == 3) ? Large : Invalid));
}

string ResourceManager::getResourceStatus() {
	//Todo get missing items from store.
	return "";
}