#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 100 + 10;
const int M = N * 4;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
struct edge {
    int to, nxt;
} e[M];
int head[M], cnt, n, m, mp[110][110], vis[N], p[N];
void add(int from, int to) {
    e[++cnt].to = to;
    e[cnt].nxt = head[from];
    head[from] = cnt;
}
int trans(int i, int j) {
    return (i - 1) * n + j;
}
bool match(int x) {
    for(int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if(!vis[y]) {
            vis[y] = 1;
            if(!p[y] || match(p[y])) {
                p[y] = x;
                return true;
            }
        }
    }
    return false;
}
int solve() {
    int ans = 0;
    memset(p, 0, sizeof(p));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if((i + j) % 2 || mp[i][j] == -1) continue;
            memset(vis, 0, sizeof(vis));
            ans = ans + match((i - 1) * n + j);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int tx, ty;
        cin >> tx >> ty;
        mp[tx][ty] = -1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if((i + j) % 2) continue;
            if(mp[i][j] != -1) {
                for(int k = 0; k < 4; k++) {
                    int px = i + dx[k];
                    int py = j + dy[k];
                    if(px > 0 && px <= n && py > 0 && py <= n && mp[px][py] != -1) {
                        int p1 = trans(i, j);
                        int p2 = trans(px, py);
                        add(p1, p2);
                    }
                }
            }
        }
    }
    cout << solve();
    return 0;
}