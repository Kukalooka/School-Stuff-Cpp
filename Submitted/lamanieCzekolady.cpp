#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    if ((k % n == 0 || k % m == 0) && k < n * m)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;

    return 0;
}