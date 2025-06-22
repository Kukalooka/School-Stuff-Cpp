#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string reverseString(const string& s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return reversed_s;
}

string complementString(const string& s) {
    string complemented_s = s;
    for (char& c : complemented_s) {
        c = (c == '0' ? '1' : '0');
    }
    return complemented_s;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<string, long long> antisymmetric_counts;
    long long total_antisymmetric_fragments = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + j <= n; ++j) {
            string fragment = s.substr(i, j);
            string reversed_complement_fragment = reverseString(complementString(fragment));

            if (fragment == reversed_complement_fragment) {
                total_antisymmetric_fragments++;
            }
        }
    }

    cout << total_antisymmetric_fragments << endl;

    return 0;
}