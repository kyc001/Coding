#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> values;

int dfs(int node, bool isAliceTurn) {
    if (tree[node].empty()) {
        return values[node];
    }
    if (isAliceTurn) {
        int maxValue = INT_MIN;
        for (int child : tree[node]) {
            maxValue = max(maxValue, dfs(child, !isAliceTurn));
        }
        return maxValue;
    } else {
        int minValue = INT_MAX;
        for (int child : tree[node]) {
            minValue = min(minValue, dfs(child, !isAliceTurn));
        }
        return minValue;
    }
}

void solve() {
    int n;
    cin >> n;
    tree.assign(n + 1, vector<int>());
    values.assign(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    cout << dfs(1, true) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}