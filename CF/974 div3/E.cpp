#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int sum = 0, f = 1;
    char c = getchar();
    while (c > '9' || c < '0')
    {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        sum = (sum << 3) + (sum << 1) + c - 48;
        c = getchar();
    }
    return sum * f;
}
typedef long long ll;
struct Node
{
    int to;
    ll d;
    inline bool operator<(const Node &b) const
    {
        return d > b.d;
    }
};
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int inf = 1e9 + 10;
int T, n, m, h;
bool horse[N], vis[N];
int dis1[N], dis2[N];
int tag = -1, sum = inf;
void dijkstra(int s, vector<Node> g[N * 2], int* dis)
{
    priority_queue<Node> q;
    q.push({s, 0});
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
    }
    while (!q.empty())
    {
        Node cur = q.top();
        q.pop();
        int u = cur.to, cost = cur.d;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); i++)
        {
            int y = g[u][i].to, z = g[u][i].d;
            if (y == u + N && z == 0)
            {
                q.push({y, cost});
            }
            if (dis[y % N + 1] > cost + z)
            {
                dis[y % N + 1] = cost + z;
                q.push({y, dis[y % N + 1]});
            }
        }
    }
}
void solve()
{
    n = read(), m = read(), h = read();
    vector<Node> g[n * 2];
    for (int i = 1; i <= n; i++)
    {
        dis1[i] = inf, dis2[i] = inf;
    }
    dis1[1] = 0, dis2[n] = 0;
    for (int i = 1; i <= h; i++)
    {
        int temp = read();
        g[temp].push_back({temp + N, 0});
    }
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        g[u + N].push_back({v + N, w / 2});
        g[v + N].push_back({u + N, w / 2});
    }
    dijkstra(1, g, dis1);
    dijkstra(n, g, dis2);
    for (int i = 1; i <= n; i++)
    {
        if (dis1[i] == dis2[i] && dis1[i] != inf && dis1[i] < sum)
        {
            tag = i;
            sum = dis1[i];
        }
    }
    printf("%d\n", tag);
}
int main()
{
    T = read();
    while (T--)
    {
        solve();
    }
    return 0;
}
// 6 2 1 1 1 1 2 10 3 1 2 2 3 1 2 10 3 3 1 2 1 2 4 1 3 10 2 3 6 4 3 2 2 3 1 2 10 2 3 18 3 4 16 3 2 1 2 1 2 4 1 3 16 7 7 1 3 1 5 2 2 6 12 1 2 12 6 4 8 7 3 4 6 3 4 7 6 4

//     5 -
//     1 6 19 14 12
