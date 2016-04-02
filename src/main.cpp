/*
 * File:   main.cpp
 * Author: Henning Meek Dromnes
 *
 * Created on April 2, 2016, 11:18 AM
 */


#include <iostream>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include <functions.h>

using namespace std;

#define KEY_Y 121
#define KEY_Y_C 89
#define KEY_ESC 27

// main() is where the program begins.
int main() {
    int num, c = 0;
    char redo;

    cout << "Welcome! This program will tell whether your input is a prime or not." << endl;
    cout << "Written by Henning Meek Dromnes." << endl;
    cout << "*********************************************************************" << endl << endl << endl;

    start:
    cout << "Enter a number:" << endl;
    cin >> num;

    if (is_prime(num)) {
        cout << num << " is a prime." << endl;
    } else {
        cout << num << " is not a prime." << endl;
    }

    cout << endl << endl;
    cout << "Press Y to continue, or ESC to quit." << endl;
    press_key:
    while(1) {
        switch ((c = getch())) {
            case KEY_Y:
                goto start;
                break;
            case KEY_Y_C:
                goto start;
                break;
            case KEY_ESC:
                goto end;
                break;
            default:
                cout << "So you found the \"any key\"? GG!" << endl << endl;
                cout << "Now press Y to continue, or ESC to quit." << endl;
                goto press_key;
        }
    }

    end:
    return 0;
}
