#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
struct edge {
    int to, val, nxt;
} e[N * 4];
int head[N], cnt;
int n, h;
queue<int> q;
int dist[N], inq[N];
void add(int u, int v, int w) {
    e[++cnt] = {v, w, head[u]};
    head[u] = cnt;
}
void SPFA() {
    memset(dist, -127, sizeof(dist));
    inq[0] = 1;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int i = head[u]; i; i = e[i].nxt) {
            if(dist[e[i].to] < dist[u] + e[i].val) {
                dist[e[i].to] = dist[u] + e[i].val;
                if(!inq[e[i].to]) {
                    q.push(e[i].to);
                    inq[e[i].to] = 1;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    for(int i = 1; i <= h; i++) {
        int x1, x2, t;
        cin >> x1 >> x2 >> t;
        add(x1 - 1, x2, t);
    }
    for(int i = 1; i <= n; i++) {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }
    SPFA();
    cout << dist[n];
    return 0;
}
