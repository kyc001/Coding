#include<bits/stdc++.h>
using namespace std;
int t;
void solve() {
    string s;
    int ans = 0, flag = 1;
    cin >> s;
    reverse(s.begin(), s.end());
    for(auto c : s) {
        if(c == '0') {
            ans += flag;
        }
        else {
            ans += 1;
            flag = 0;
        }
    }
    cout << ans - 1 << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}