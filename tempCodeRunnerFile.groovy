#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    // 动态规划计算最小通关关卡数量
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (points[i] > 0) {
            for (int j = 1; j <= points[i] && i + j <= n; ++j) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    int min_steps = dp[n] == INT_MAX ? -1 : dp[n];

    // 贪心算法计算能够成功通关的最大困难指数
    int max_k = k;
    for (int i = 0; i < n; ++i) {
        if (points[i] > 0) {
            max_k = max(max_k, points[i]);
        }
    }

    cout << min_steps << " " << max_k << endl;
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