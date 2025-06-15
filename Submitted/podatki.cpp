#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    auto is_prime = [](long long num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (long long i = 5; i * i <= num; i = i + 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    };

    if (is_prime(n)) {
        cout << 1 << endl;
    } else if (n % 2 == 0) {
        cout << 2 << endl;
    } else {
        if (is_prime(n - 2)) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}