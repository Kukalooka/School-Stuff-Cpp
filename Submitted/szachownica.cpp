#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % 2 == 0)
                cout << (i % 2 != 0);
            else
                cout << (i % 2 == 0);
        }
        cout << endl;
    }

    return 0;
}