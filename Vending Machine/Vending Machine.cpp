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
    int code = 0;
    do {
        cout << "Choose Operation:\n0.Exit\n1.Create\n2.Update\n3.Delete\n4.Reset\n5.Print status";
        cin >> code;
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
        default:
            cout << "Choice doesn't exist. Please re-enter choice.";
            break;
        }
    } while (code != 0);
}

void consume(ResourceManager*& resources) {
    int code = 0;
    do {
        cout << "::::::::::::::::::::::::::::::::::::::::::"<<endl;
        cout << "WELCOME TO THE BEVERAGE VENDING MACHINE!" << endl;
        cout << "Choose your option:\n0.Exit\n1.View Items\n2.Buy Items\n3.Add Credit\n4.Print All Data";
        cin >> code;
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
            cout << "Choice doesn't exist. Please re-enter choice.";
            break;
        }
    } while (code != 0);
}

int main()
{
    cout << "Welcome to Beverage Dispenser API!\n";
    cout << "::::::::::::::::::::::::::::::::::\n";
    cout << "Initializing Beverage Dispenser with items..." << endl;
    cout << "::::::::::::::::::::::::::::::::::\n";

    ResourceManager* resources = ResourceManager::getInstance();
    //Fills the vending machine with beverages.
    resources->fillMachine();
    resources->printItems();

    int code = 0;
    do {
        cout << "Choose Role:\n0.Exit\n1.Operator\n2.Consumer";
        cin >> code;
        switch (code) {
            case 0:
                break;
            case 1: maintain(resources);
                break;
            case 2: consume(resources);
                break;
            default:
                cout<<"Choice doesn't exist. Please re-enter choice.";
                break;
        }
    } while (code != 0);

    cout << "::::::::::::::::::::::::::::::::::\n";
    cout << "Thanks for using the vending machine!"<<endl;

    return 0;
}

