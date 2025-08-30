#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, x, y;
void exgcd(ll a, ll b) {
    if(b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b);
    ll temp = x;
    x = y;
    y = temp - y * (a / b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    exgcd(a, b);
    cout << (x % b + b) % b;
    return 0;
}