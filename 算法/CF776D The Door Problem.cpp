#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int rk[N * 2], fa[N * 2], n;
void init() {
    for(int i = 1; i <= n * 2; i++) {
        rk[i] = 0;
        fa[i] = i;
    }
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int i, int j) {
    int x = find(i);
    int y = find(j);
    if(x != y) {
        // 将 rank 小的树合并到 rank 大的树上
        if(rk[x] < rk[y]) {
            fa[x] = y;
        } else {
            fa[y] = x;
            // 只有当两个树的 rank 相等时，新根的 rank 才需要加 1
            if(rk[x] == rk[y]) {
                rk[x]++;
            }
        }
    }
}
int m;
int t[N], key[N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int c;
            cin >> c;
            if(key[c][0])
                key[c][1] = k;
            else
                key[c][0] = k;
        }
    }
    for(int i = 1; i <= n; i++) {
        int a = key[i][0], b = key[i][1];
        if(t[i] == 1) {
            merge(a, b);
            merge(a + n, b + n);
        } else {
            merge(a + n, b);
            merge(a, b + n);
        }
        if(find(a) == find(a + n) || find(b) == find(b + n)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}