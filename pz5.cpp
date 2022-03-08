#include <iostream>
#include <cmath>

using namespace std;

int is_prime(int number) {
    for (int i = 2; i <= sqrt(number); i++) {
        if (!(number % i)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i = 0, num = 2;
    cin >> n;
    while (n != i) {
        if (is_prime(num)) {
            cout << num << " ";
            i++;
        }
        num++;
    }
}
