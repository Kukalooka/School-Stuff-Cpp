#include <iostream>
#include <vector>

using namespace std;

int s;
vector<vector<int>> adj;
vector<bool> visited;
long long count_paths = 0;

void findPaths(int u, int path_length) {
    if (path_length == s) {
        for (int neighbor : adj[u]) {
            if (neighbor == 1) {
                count_paths++;
                break;
            }
        }
        return;
    }

    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            findPaths(neighbor, path_length + 1);
            visited[neighbor] = false;
        }
    }
}

int main() {
    int u;
    cin >> s >> u;

    adj.resize(s + 1);
    visited.assign(s + 1, false);

    for (int i = 0; i < u; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited[1] = true;
    findPaths(1, 1);

    cout << count_paths << endl;

    return 0;
}