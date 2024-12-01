#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> bets(n);
    for (int i = 0; i < n; ++i) {
        cin >> bets[i];
    }

    string t;
    cin >> t;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t) {
            ans += bets[i];
        } else {
            // 根据规则判断后续轮次（这里简单处理）
            if ((t == "up" && (s[i] == "down" || s[i] == "right" || s[i] == "left")) ||
                (t == "down" && (s[i] == "up" || s[i] == "right" || s[i] == "left")) ||
                (t == "right" && (s[i] == "up" || s[i] == "down" || s[i] == "left")) ||
                (t == "left" && (s[i] == "up" || s[i] == "down" || s[i] == "right"))) {
                ans += bets[i];
            }
        }
    }

    cout << ans << endl;

    return 0;
}