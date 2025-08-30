#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n, k;
int fa[N * 3], rk[N * 3];
void init() {
    for(int i = 1; i <= n * 3; i++) {
        fa[i] = i;
        rk[i] = 0;
    }
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int i, int j) {
    int x = find(i), y = find(j);
    if(x != y) {
        if(rk[x] < rk[y]) {
            fa[x] = y;
        } else {
            fa[y] = x;
            if(rk[x] == rk[y]) {
                rk[x]++;
            }
        }
    }
}
int ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    init();
    for(int i = 1; i <= k; i++) {
        int tag, x, y;
        cin >> tag >> x >> y;
        if(x > n || x < 1 || y > n || y < 1) {
            ans++;
            continue;
        }
        if(tag == 1) {  // tag=1 xy是同类
            if(find(x) == find(y + n * 2) || find(x + n * 2) == find(y)) {
                ans++;
                continue;
            }
            merge(x, y);
            merge(x + n, y + n);
            merge(x + n * 2, y + n * 2);
        } else {  // tag=2 x吃y
            if(find(x + n * 2) == find(y) || find(x) == find(y) || x == y) {
                ans++;
                continue;
            }
            merge(x + n, y);
            merge(x + n * 2, y + n);
            merge(x, y + n * 2);
        }
    }
    cout << ans;
    return 0;
}