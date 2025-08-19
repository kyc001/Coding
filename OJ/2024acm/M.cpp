#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N];
set<int> not_dislike[N]; // 存储每个玩家不讨厌的其他玩家编号

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    // 构建不讨厌关系
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        not_dislike[u].insert(v);
        not_dislike[v].insert(u);
    }

    vector<long long> tot(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        for (int j : not_dislike[i])
        {
            if (j > i)
            {
                int maxS = max(a[i] + b[j], a[j] + b[i]);
                tot[i] += maxS;
                tot[j] += maxS;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << tot[i] << " ";
    }
    cout << endl;

    return 0;
}