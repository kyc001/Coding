#include<bits/stdc++.h>
using namespace std;
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
const int MOD = 10086;
const int len = 30;
int n, q, p[40], cnt = 1, k, t = 1;
void insert(int x) {
    for(int i = len; i >= 0; i --) {
        if(x >> i & 1) {
            if(!p[i]) {
                p[i] = x;
                break;
            }
            x^= p[i];
            if(!x) {
                (cnt <<= 1) %= MOD;
                break;
            }
        }
    }
}
int main() {
    n = read();
    for(int i = 1; i <= n; i ++) {
        int temp = read();
        insert(temp);
    }
    q = read();
    for(int i = 0; i <= len; i ++) {
        if(p[i]) {
            if((q >> i) & 1) (k += t) %= MOD;
            t <<= 1;
        }
    }
    printf("%d", (k * cnt + 1) % MOD);
    return 0;
}
