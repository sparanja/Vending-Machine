// Vending Machine.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    Author: Sumanth Paranjape
    email: sparanj2@asu.edu
*/
//

#include <iostream>
#include <string>
#include "ResourceManager.h"
#include "SizeEnum.h"
using namespace std;

void maintain(ResourceManager*& resources) {
    int code;
    string codeStr;
    do {
        try
        {
            std::cout << "Choose Operation:\n0.Exit\n1.Create\n2.Update\n3.Delete\n4.Reset\n5.Get All"
                         "\n6. Get By ID\n7.Delete All\n8.Delete By ID";
            getline(cin, codeStr, '\n');
            code = stoi(codeStr);
            switch (code) {
            case 0:
                break;
            case 1: resources->create(false);
                break;
            case 2: resources->update();
                break;
            case 3: resources->delete_item();
                break;
            case 4: resources->reset();
                break;
            case 5: resources->printItems();
                break;
            case 6: resources->getByID(false);
                break;
            case 7: resources->deleteAll();
                break;
            case 8: resources->deleteByID();
                break;
            default:
                std::cout << "Choice doesn't exist. Please re-enter choice.";
                break;
            }
        }
        catch (const std::exception&)
        {
            std::cout << "Exception occured while parsing, make sure to enter a number.";
            code = 1;
        }
        
    } while (code != 0);
}

void consume(ResourceManager*& resources) {
    int code;
    string codeStr;
    do {
        try
        {
            std::cout << "::::::::::::::::::::::::::::::::::::::::::" << endl;
            std::cout << "WELCOME TO THE BEVERAGE VENDING MACHINE!" << endl;
            std::cout << "Choose your option:\n0.Exit\n1.View Items\n2.Buy Items\n3.Add Credit\n4.Print All Data";
            getline(cin, codeStr, '\n');
            code = stoi(codeStr);
            switch (code) {
            case 0:
                break;
            case 1: resources->viewItemSet();
                break;
            case 2: resources->buyItems();
                break;
            case 3: resources->rechargeAccount();
                break;
            case 4: resources->printItems();
                break;
            default:
                std::cout << "Choice doesn't exist. Please re-enter choice.";
                break;
            }
        }
        catch (const std::exception&)
        {
            std::cout << "Exception occured while parsing, make sure to enter a number.";
        }
        
    } while (code != 0);
}

int main()
{
    std::cout << "Welcome to Beverage Dispenser API!\n";
    std::cout << "::::::::::::::::::::::::::::::::::\n";
    std::cout << "Initializing Beverage Dispenser with items..." << endl;
    std::cout << "::::::::::::::::::::::::::::::::::\n";

    ResourceManager* resources = ResourceManager::getInstance();
    //Fills the vending machine with beverages.
    resources->fillMachine();
    resources->printItems();
    int code;
    do {
        try
        {
            string codeStr;
            std::cout << "Choose Role:\n0.Exit\n1.Operator\n2.Consumer";
            getline(cin, codeStr, '\n');
            code = stoi(codeStr);
            switch (code) {
            case 0:
                break;
            case 1: maintain(resources);
                break;
            case 2: consume(resources);
                break;
            default:
                std::cout << "Choice doesn't exist. Please re-enter choice.";
                break;
            }
        }
        catch (const std::exception&)
        {
            std::cout << "Exception occured while parsing, make sure to enter a number.";
        }
    } while (code != 0);

    std::cout << "::::::::::::::::::::::::::::::::::\n";
    std::cout << "Thanks for using the vending machine!"<<endl;

    return 0;
}

