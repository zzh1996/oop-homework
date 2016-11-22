#include <iostream>
#include <std_lib_facilities.h>

bool isprime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    vector<int> v;
    for (int i = 1; i <= 200; i++) {
        if (isprime(i))
            v.push_back(i);
    }
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << '\t';
    }
    return 0;
}