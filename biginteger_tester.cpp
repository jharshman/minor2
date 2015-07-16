/**
 * biginteger_tester.cpp
 * written by Josh Harshman
 * 07/14/15
 *
 * NOTE: Driver templated from previous assignment
 * */

#include "biginteger.h"
void displaymenu();
int main(void) {


        BigInt c1, c2;

        //Get our  numbers to tinker with
        cout << "Enter two numbers separated by a space: ";
        cin >> c1 >> c2;
        cout << "You Entered:\n" << c1 << " and " << c2 << endl;

        //implement menu
        int choice;
        do {
                displaymenu();
                cout << "Enter Selection: ";
                cin >> choice;
                switch(choice) {
                        case 1:
                                //execute add
                                cout << "Addition yields: " << c1 + c2 << endl;
                                break;
                        case 2:
                                //execute subtract
                                cout << "Subtraction yields: " << c1 - c2 << endl;
                                break;
                        case 3: 
                                //execute multiply
                                cout << "Multiplication yields: " << c1 * c2 << endl;
                                break;
                        case 4:
                                //quitting
                                cout << "ending..." << endl;
                                break;
                        default:
                                //not expected
                                cout << "Please select a valid menu item." << endl;
                                
                }
        }while(choice!=4);

        return 0;
}


void displaymenu() {
        cout << "1. add" << endl;
        cout << "2. subtract" << endl;
        cout << "3. multiply" << endl;
        cout << "4. quit" << endl;
}

