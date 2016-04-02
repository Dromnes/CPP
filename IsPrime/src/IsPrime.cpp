/*
 * File:   IsPrime.cpp
 * Author: Kodemikkel
 *
 * Created on 1. april 2016, 21:18
 */

 /*
 * TODO:
 *  Add the possibility to check float numbers, not just integers (if possible)
 */

#include "is_prime.h"

#define U_Y 89 // Uppercase letter 'Y' code
#define L_Y 121 // Lowercase letter 'y' code

int main() {
  int number, c;
  // "input" label
  input:
    cout << "Enter a number: ";
    cin >> number;
    // Verify the input, if it's not an integer, ask for input again
    // If we do not verify the input, the program will loop until stopped when some other data type is entered
    if(!cin) {
      cin.clear();
      cin.ignore();
      cout << "The value you specified is not an integer." << endl;
      goto input;
    }
    if(is_prime(number)) {
      cout << "The number you've entered (" << number << ") is a prime number." << endl;
    } else {
      cout << "The number " << number << " is not a prime number." << endl;
    }

    cout << "Press \"Y\" to enter another number or any other key to exit." << endl;
    // Check if the key "Y" is pressed, if so, return to "input" label
    while(1) {
      // getch() returns the key code for the button pressed (integer)
      switch((c = getch())) {
        case U_Y:
          goto input;
          break;
        case L_Y:
          goto input;
          break;
        default:
          return 0;
      }
    }
}
