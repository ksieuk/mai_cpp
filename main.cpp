#include <iostream>
using namespace std;

int mains() {
    int32_t number, num;
    int i = 0, power = 1;
    cout << "Enter number: ";
    cin >> number;

    num = number;
    while (num) {
        num /= 10;
        i++;
        power *= 10;
    }

    for (i; i > 0; 1) {
        i--;
        power /= 10;
        if ((number / power) > 0) {
            cout << "+";
        }
        if ((number / power) != 0) {
            cout << number / power << "*10^" << i;
        }
        number %= power;
    }
    return 0;
}