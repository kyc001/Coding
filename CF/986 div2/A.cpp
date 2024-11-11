#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, a, b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    int tot = 0;
    int x = 0, y = 0;
    while (tot <= 1000 && !(x == a && y == b))
    {
        if (s[tot % n] == 'N')
            y++;
        else if (s[tot % n] == 'S')
            y--;
        else if (s[tot % n] == 'W')
            x--;
        else if (s[tot % n] == 'E')
            x++;
        // cout<<x<<" "<<y<<endl;
        tot++;
    }
    if (x == a && y == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}