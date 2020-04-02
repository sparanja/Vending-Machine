#pragma once
#include <vector>
#include "Soda.h"
#include "Coffee.h"
#include "Tea.h"
#include "Fruit.h"
#include "Milk.h"
#include <unordered_set>

class ResourceManager
{
private:
	//Singleton Design Pattern used here. Cannot be instantiated.
	ResourceManager();
	static ResourceManager* r_instance;

public:
	//In-memory datastores
	vector<Beverage> availableBeverages;
	unordered_set<string> itemSet;
	vector<string> beverageTypes;
	int credits;

	//Vending Machine Actions.
	static ResourceManager* getInstance();
	void fillMachine();
	string getResourceStatus();
	void printItems();
	void viewItemSet();
	void buyItems();
	void rechargeAccount();
	void fillItems(vector<string>& brand_labels, vector<Drink_Size> drink_Size, string beverage);

	//Helper functions
	Drink_Size getDrinkSize(int val); 
	vector<string> converToParams(Beverage beverage, string type);
	int getRandom(int x, int y);
	vector<string> splitString(string str, char delim);
	int exists(Beverage beverage);
	bool isValid(Drink_Size size, int calories, int price, int quantity);

	//CRUD Operations
	void create(bool isUpdate);
	void update(vector<string>& paramList, bool isUpdate);
	void update();
	void delete_item();
	void reset();
};

