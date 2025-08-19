#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005; // 2 * n
const long long INF = 1e18;

struct Edge
{
    int to;
    long long weight;
};

vector<Edge> graph[MAXN];
long long dist[MAXN];
bool inQueue[MAXN];
int cnt[MAXN];

void addEdge(int from, int to, long long weight)
{
    graph[from].push_back({to, weight});
}

bool spfa(int n)
{
    queue<int> q;
    fill(dist, dist + n + 1, INF);
    fill(inQueue, inQueue + n + 1, false);
    fill(cnt, cnt + n + 1, 0);

    dist[0] = 0;
    q.push(0);
    inQueue[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        for (const auto &edge : graph[u])
        {
            int v = edge.to;
            long long w = edge.weight;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                if (!inQueue[v])
                {
                    q.push(v);
                    inQueue[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n)
                    {
                        return false; // Negative cycle detected
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 2 * n; ++i)
    {
        addEdge(i, (i + 1) % (2 * n), a[i]);
        addEdge((i + 1) % (2 * n), i, -a[i]);
    }

    if (spfa(2 * n))
    {
        long long min_vines = *min_element(dist, dist + 2 * n);
        cout << min_vines << endl;
    }
    else
    {
        cout << -1 << endl; // No solution
    }

    return 0;
}