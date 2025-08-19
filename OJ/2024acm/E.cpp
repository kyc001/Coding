#include <bits/stdc++.h>
using namespace std;

int T = 10;
int f, t;


void solve()
{
    cin >> f >> t;
    int temp;
    long long a = 0, k = 1;
    cin >> temp;
    while (temp != -1) {
        a += temp * k;
        k *= f;
        cin >> temp;
    }
    if(a == 0) {
        cout << 0 << endl;
        return;
    }
    while(a) {
        cout << a % t << " ";
        a /= t;
    }
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (T--)
    {
        solve();
    }
    return 0;
}