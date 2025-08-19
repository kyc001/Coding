#include <bits/stdc++.h>
using namespace std;

// 并查集查找函数
int find(vector<int> &parent, int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

// 并查集合并函数
void unionSet(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (xroot == yroot)
        return;
    if (rank[xroot] < rank[yroot])
    {
        parent[xroot] = yroot;
    }
    else if (rank[xroot] > rank[yroot])
    {
        parent[yroot] = xroot;
    }
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<int, int>> attacks(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> attacks[i].first >> attacks[i].second;
    }

    for (const auto &attack : attacks)
    {
        int a = attack.first;
        int b = attack.second;
        vector<bool> damaged(n + 1, false);
        damaged[a] = true;
        damaged[b] = true;
        vector<int> parent(n + 1);
        vector<int> rank(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int j = 1; j <= n; ++j)
        {
            if (!damaged[j])
            {
                for (int k : graph[j])
                {
                    if (!damaged[k])
                    {
                        unionSet(parent, rank, j, k);
                    }
                }
            }
        }

        unordered_set<int> components;
        for (int j = 1; j <= n; ++j)
        {
            if (!damaged[j])
            {
                components.insert(find(parent, j));
            }
        }

        cout << components.size() << endl;
    }

    return 0;
}