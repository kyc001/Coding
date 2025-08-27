#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int M = 200000 + 10;
int cnt, to[M], val[M], nxt[M], head[N];
int n, m, s;
int dis[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
void add(int x, int y, int v) {
    to[++cnt] = y;
    val[cnt] = v;
    nxt[cnt] = head[x];
    head[x] = cnt;
}
void dijkstra(int x) {
    memset(dis, 127, sizeof(dis));
    dis[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int dist = p.first, y = p.second;
        if(dist > dis[y]) continue;
        for(int i = head[y]; i; i = nxt[i]) {
            if(dis[to[i]] > dist + val[i]) {
                dis[to[i]] = dist + val[i];
                q.push({dis[to[i]], to[i]});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra(s);
    return 0;
}