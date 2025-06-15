#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long przed_poprzednim_max = 0;
    long long poprzedni_max = 0;

    for (int i = 0; i < n; ++i) {
        long long h;
        cin >> h;

        long long aktualny_max = max(poprzedni_max, h + przed_poprzednim_max);

        przed_poprzednim_max = poprzedni_max;
        poprzedni_max = aktualny_max;
    }

    cout << poprzedni_max << endl;

    return 0;
}