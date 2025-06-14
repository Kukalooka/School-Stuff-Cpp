#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> bulbs(n + 1, false);

    for (int i = 0; i < k; ++i) {
        int switch_num;
        cin >> switch_num;

        if (switch_num >= 1 && switch_num <= n) {
            bulbs[switch_num] = !bulbs[switch_num];
        }
    }

    int lit_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (bulbs[i]) {
            lit_count++;
        }
    }

    cout << lit_count << endl;

    return 0;
}