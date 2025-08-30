#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 10;
const int M = 100000 + 10;
struct edge {
    int a, b, c;
} e[M];
bool cmp(edge x, edge y) {
    return x.c > y.c;
}
int n, m;
int rk[N * 2], fa[N * 2];
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c;
    }
    sort(e + 1, e + 1 + m, cmp);
    for(int i = 1; i <= m; i++) {
        if(find(e[i].a) == find(e[i].b)) {
            cout << e[i].c;
            return 0;
        }
        merge(e[i].a, e[i].b + n);
        merge(e[i].a + n, e[i].b);
    }
    cout << 0;
    return 0;
}