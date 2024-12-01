#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    if(m > n) {
        if(n >= 2) cout << 3 << endl;
        else cout << 2 << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
