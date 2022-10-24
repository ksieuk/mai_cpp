#include <iostream>
#include <cmath>
using namespace std;


int is_prime(int number, const int prime_numbers[]) {
    int j = 0;
    while (prime_numbers[j] != 0) {
        if (number % prime_numbers[j] == 0) {
            return 0;
        }
        j++;
    }
    return 1;
}

int main() {
    int n, i = 1, num = 3;
    cin >> n;
    int prime_numbers[n] = {2};

    if (n < 1) {
        return 0;
    }
    cout << 2 << ' ';
    while (n > i) {
        if (is_prime(num, prime_numbers)) {
            cout << num << ' ';
            prime_numbers[++i] = num;
        }
        num++;
    }
}
