#include <iostream>

using namespace std;

int main() {
    int licz2, licz5, licz6, licz3;
    cin >> licz2 >> licz3 >> licz5 >> licz6;

    cout << min(licz2, min(licz5, licz6)) * 256 + min(licz3, licz2 - min(licz2, min(licz5, licz6))) * 32 << endl;

    return 0;
}