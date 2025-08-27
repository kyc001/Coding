#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
int T, n, mp[N][N], p[N], vis[N];
bool match(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (mp[i][j] && !vis[j])
        {
            vis[j] = 1;
            if (!p[j] || match(p[j]))
            {
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}
int solve()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        cnt += match(i);
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> mp[i][j];
            }
        }
        int ans = solve();
        if (ans == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}