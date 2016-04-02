

bool is_prime(int num) {
    int i;
    bool prime = true;

    for ( i = 2; i < num;  i++) {
        if (!(num % i)) {
            prime = false;
            cout << "The number can be divided by: " << i << endl;
        }
    }
    if (prime) {
        return true;
    } else {
        return false;
    }
}
