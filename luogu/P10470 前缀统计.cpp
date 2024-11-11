#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int T, n, q;
int son[N][70], cnt[N], idx;
void insert(string str) {
    int p = 0;
    for(int i = 0; i < str.size(); i ++) {
        int u = str[i] - 'a';
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
    return;
}
int query(string str) {
    int p = 0, ans = 0;
    for (int i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if(!son[p][u]) {
            return ans;
        }
        p = son[p][u];
        ans += cnt[p];
    }
    return ans;
}
void init() {
    for(int i = 0; i <= idx; i ++) {
        for (int j = 0; j <= 65; j ++) {
            son[i][j] = 0;
        }
        cnt[i] = 0;
    }
    idx = 0;
    return;
}
void solve() {
    init();
    string s;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> s;
        insert(s);
    }
    for(int i = 1; i <= q; i ++) {
        cin >> s;
        cout << query(s) << endl;
    }
    return;
}
int main() {
    solve();
    return 0;
}