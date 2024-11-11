#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
   int sum = 0, f = 1;
   char c = getchar();
   while(c > '9' || c < '0') {
       if(c == '-') f = -f;
       c = getchar();
   }
   while(c >= '0' && c <= '9') {
       sum = (sum << 3) + (sum << 1) + c - 48;
       c = getchar();
    }
   return sum * f;
}
const int N = 100 + 10;
int k, a[N], d[32], temp;
ll ans;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    k = read();
    for(int i = 1; i <= k; i ++)
        a[i] = read();
    sort(a + 1, a + 1 + k, cmp);
    for(int i = 1; i <= k; i ++) {
        temp = a[i];
        for(int j = 30; j >= 0; j --) {
            if(temp & (1ll << j)) {
                if(d[j]) temp ^= d[j];
                else {
                    d[j] = temp;
                    break;
                }
            }
        }
        if(!temp) ans += a[i];
    }
    cout << ans;
    return 0;
}
