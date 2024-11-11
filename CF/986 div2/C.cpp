#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, v, s[N], pf[N], sf[N];

void solve()
{
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int s1 = 0, s2 = 0;
    for (int i = 1, lst = 0; i <= n; i++)
        if (s[i] - s[lst] >= v)
            pf[++s1] = lst = i;

    sf[0] = n + 1;
    for (int i = n, lst = n + 1; i >= 1; i--)
        if (s[lst - 1] - s[i - 1] >= v)
            sf[++s2] = lst = i;

    if (s1 < m)
    {
        cout << -1 << endl;
        return;
    }

    int ans = -1;
    for (int i = 0; i <= m; i++)
        if (pf[i] < sf[m - i])
            ans = max(ans, s[sf[m - i] - 1] - s[pf[i]]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}