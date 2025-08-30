#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
ll n, a[N], b[N];
ll p = 1, ans;

ll mod(ll x, ll p) {
    return (x % p + p) % p;
}

ll mod_mul(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while(b > 0) {
        if(b & 1) res = (res + a) % m;
        a = (a * 2) % m;
        b >>= 1;
    }
    return res;
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - y * (a / b);
}

ll inv(ll m, ll n) {
    ll x = 0, y = 0;
    exgcd(m, n, x, y);
    return mod(x, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        p *= a[i];
    }

    for(int i = 1; i <= n; i++) {
        ll r_i = p / a[i];
        ll inv_r_i = inv(r_i, a[i]);

        ll term = mod_mul(b[i], r_i, p);
        term = mod_mul(term, inv_r_i, p);

        ans = mod(ans + term, p);
    }

    cout << ans;
    return 0;
}