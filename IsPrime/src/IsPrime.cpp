/*
 * File:   main.cpp
 * Author: Kodemikkel
 *
 * Created on 1. april 2016, 21:18
 */

 /*
 * ToDo:
 *  Add the posibility to check float numbers, not just integers (if possible)
 *  Add single keypress to exit, now you have to enter a value to exit
 */

#include <iostream>

using namespace std;

bool is_prime(int number) {
  int i;
  bool prime = true;
  for(i = 2; i < number; i++) {
    if(!(number % i)) {
      cout << "Dividable by " << i << endl;
      prime = false;
    }
  } if (prime) {
      return true;
  } else {
      return false;
  }
}

int main() {
    char redo;
    do{
      int number;
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

        cout << "Type 'y' or 'Y' to enter another number or any other value to exit." << endl;
        cin >> redo;

        } while(redo == 'y' || redo == 'Y');

      return 0;
}
