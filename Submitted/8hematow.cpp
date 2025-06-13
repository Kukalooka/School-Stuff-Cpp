#include <iostream>
#include <vector>
using namespace std;

int n, result = 0;
vector<bool> cols, diag1, diag2;

void solve(int row) {
    if (row == n) {
        result++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
            continue;

        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
        solve(row + 1);
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
}

int main() {
    cin >> n;
    cols.assign(n, false);
    diag1.assign(2 * n - 1, false);
    diag2.assign(2 * n - 1, false);

    solve(0);
    cout << result << endl;
    return 0;
}
