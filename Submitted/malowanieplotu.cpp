#include <iostream>
#include <vector>

using namespace std;

void update(vector<int>& bit, int index, int value) {
    while (index < bit.size()) {
        bit[index] += value;
        index += index & (-index);
    }
}

int query(const vector<int>& bit, int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> bit(n + 2, 0);

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            update(bit, l, 1);
            update(bit, r + 1, -1);
        } else {
            int a;
            cin >> a;
            cout << query(bit, a) << "\n";
        }
    }

    return 0;
}