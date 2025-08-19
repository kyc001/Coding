#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
int depth[MAXN];
int parent[MAXN];
int up[MAXN][20];

// 构建树的邻接表
void buildTree(int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

// 预处理深度、父节点和倍增数组
void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[v] = p;
    up[v][0] = p;
    for (int i = 1; i < 20; ++i)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : tree[v])
    {
        if (u != p)
        {
            dfs(u, v, d + 1);
        }
    }
}

// 计算最近公共祖先
int lca(int a, int b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    for (int i = 19; i >= 0; --i)
    {
        if (depth[up[a][i]] >= depth[b])
        {
            a = up[a][i];
        }
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; --i)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return parent[a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    buildTree(n);
    dfs(1, 1, 0);

    set<int> s;
    while (q--)
    {
        int op, k;
        cin >> op >> k;
        if (op == 1)
        {
            if (s.find(k) != s.end())
            {
                s.erase(k);
            }
            else
            {
                s.insert(k);
            }
        }
        else if (op == 2)
        {
            int ans = 0;
            for (int u : s)
            {
                ans += lca(k, u);
            }
            cout << ans << endl;
        }
        else if (op == 3)
        {
            int minVal = -1;
            for (int u : s)
            {
                if (lca(u, k) == k)
                {
                    if (minVal == -1 || u < minVal)
                    {
                        minVal = u;
                    }
                }
            }
            if (minVal == -1)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << minVal << endl;
            }
        }
    }

    return 0;
}