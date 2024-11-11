#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n, m;
ll d[100], ans;
void upd(ll x) {
    for(int i = 60; i >= 0; i --) {
        if(x & (1ll << i)) {
            if(d[i])
                x ^= d[i];
            else {
                d[i] = x;
                break;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        ll temp = 0;
        cin >> s;
        for(int i = 0; i < n; i ++) {
            temp |= (ll)(s[i] == 'O') << i;
        }
        upd(temp);
    }
    for(int i = 60; i >= 0; i --) {
        if(d[i]) {
            ans ++;
        }
    }
    cout << (1LL << ans) % 2008;
    return 0;
}