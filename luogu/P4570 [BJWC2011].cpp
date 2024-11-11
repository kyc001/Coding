#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
   ll sum = 0;int f = 1;
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
const int N = 1000 + 10;
struct node{
    ll a;
    int b;
}stone[N];
int n, ans;
ll d[64];
bool cmp(node x, node y) {
    return x.b > y.b;
}
void upd(ll x, int y) {
    for(int i = 60; i >= 0; i --) {
        if(x & (1ll << i)) {
            if(d[i]) x ^= d[i];
            else {
                d[i] = x;
                ans += y;
                break;
            }
        }
    }
}
int main() {
    n = read();
    for(int i = 1; i <= n; i ++) {
        stone[i].a = read(), stone[i].b = read();
    }
    sort(stone + 1, stone + 1 + n, cmp);
    for(int i = 1; i <= n; i ++) {
        upd(stone[i].a, stone[i].b);
    }
    printf("%d", ans);
    return 0;
}