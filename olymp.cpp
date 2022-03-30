#include <iostream>
#include <cmath>

int main() {
    int n, res = INT_MAX, counter = 0;
    std::cin >> n;

    int dividers[1000] = {0};
    int dividers_amount[1000] = {0};

    int m = n;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            dividers[counter] = i;
            while (m % i == 0) {
                m /= i;
                dividers_amount[counter]++;
            }
            counter++;
        }
    }

    if (m > 1) {
        dividers[counter] = m;
        dividers_amount[counter] = 1;
        counter++;
    }

    for (int i = 0; i < counter; i++) {
        m = n;
        int ans = 0;
        while (m > 0) {
            m /= dividers[i];
            ans += m;
        }
        res = std::min(res, ans / dividers_amount[i]);
    }
    std::cout << res;
}
