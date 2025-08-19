#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 10;

int fa[MAXN], rk[MAXN];
int n, m, p;

inline void init(int n) {
    for(int i = 1; i <= n; i ++) {
        fa[i] = i;
        rk[i] = 1;
    }
}

int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j) {
    int x = find(i), y = find(j);
    if(rk[x] <= rk[y])
        fa[x] = y;
    else
        fa[y] = x;
    if(fa[x] == fa[y] && x != y)
        rk[y] ++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> p;
    init(n);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    for(int i = 1; i <= p; i ++) {
        int x, y;
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes\n" : "No\n");
    }
    return 0;
}