#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int Inv[N] = {0, 1};
long long n, p;
int mod(long long x, long long p) {
    return (x % p + p) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    cout << 1 << endl;
    for(int i = 2; i <= n; i++) {
        Inv[i] = mod((long long) -(p / i) * Inv[p % i], p);
        cout << Inv[i] << "\n";
    }
    return 0;
}