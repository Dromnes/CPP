/* 
 * File:   is_prime.h
 * Author: Kodemikkel
 *
 * Created on 2. april 2016, 14:32
 */

#ifndef __IS_PRIME_INCLUDED__
#define __IS_PRIME_INCLUDED__

#include <iostream>
#include <conio.h>


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

#endif