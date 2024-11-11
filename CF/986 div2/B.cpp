#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, b, c;
    cin >> n >> b >> c;

    if (b == 0)
    {
        if (c < n - 2)
            cout << -1 << endl;
        else if (c == n - 2)
            cout << n - 1 << endl;
        else if (c == n - 1)
            cout << n - 1 << endl;
        else
            cout << n << endl;

        return;
    }

    if (c > n - 1)
        cout << n << endl;
    else
    {
        long long num = (n - 1 - c) / b + 1;
        cout << n - num << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}