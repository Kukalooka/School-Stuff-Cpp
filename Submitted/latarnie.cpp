#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    long long d, k;
    vector<long long> pos;

    cin >> d >> k;

    for (int i = 0; i < k; ++i) {
        long long x;
        cin >> x;
        pos.push_back(x);
    }

    sort(pos.begin(), pos.end());
    double min_promien = max((double)pos[0], (double)(d - pos.back()));

    for (int i = 0; i < k - 1; ++i) {
        double przerwa = (double)(pos[i+1] - pos[i]) / 2.0;

        if (przerwa > min_promien) {
            min_promien = przerwa;
        }
    }

    cout << fixed << setprecision(1);
    cout << min_promien;

    return 0;
}