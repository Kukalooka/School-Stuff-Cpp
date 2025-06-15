#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

void rozwiaz() {
    int n;
    cin >> n;

    map<int, vector<int>> pozycje_kolorow;

    for (int i = 0; i < n; ++i) {
        int kolor;
        cin >> kolor;
        pozycje_kolorow[kolor].push_back(i);
    }

    int min_odleglosc = INT_MAX;
    int max_odleglosc = 0;
    bool czy_znaleziono_pare = false;

    for (auto const& para : pozycje_kolorow) {
        const vector<int>& pozycje = para.second;

        if (pozycje.size() < 2) {
            continue;
        }

        czy_znaleziono_pare = true;

        max_odleglosc = max(max_odleglosc, pozycje.back() - pozycje.front());

        for (size_t i = 1; i < pozycje.size(); ++i) {
            min_odleglosc = min(min_odleglosc, pozycje[i] - pozycje[i - 1]);
        }
    }

    if (!czy_znaleziono_pare) {
        cout << "0 0\n";
    } else {
        cout << min_odleglosc << " " << max_odleglosc << "\n";
    }
}

int main() {
    rozwiaz();

    return 0;
}