#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int Log2[N], Min[N][16], Max[N][16];
int n, q, a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> Min[i][0];
        Max[i][0] = Min[i][0];
    }
    for(int i = 2; i <= n; i++) Log2[i] = Log2[i >> 1] + 1;
    for(int i = 1; i <= 16; i++){
        for(int j = 1; j + (1 << i) - 1 <= n; j++){
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    }
    while(q--){
        cin >> a >> b;
        int k = Log2[b - a + 1];
        cout << max(Max[a][k], Max[b - (1 << k) + 1][k]) - min(Min[a][k], Min[b - (1 << k) + 1][k]) << '\n';
    }
    return 0;
}