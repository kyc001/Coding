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
const int N = 1e5 + 10;
const int M = 31 * N;
int n, m, sum[N];
int son[M][2], cnt[M], idx = 0, ans;
void insert(int u, int c) {
    int p = 0;
    for(int i = 30; i >= 0; i --) {
        int x = u >> i & 1;
        if(!son[p][x]) {
            son[p][x] = ++ idx;
        }
        p = son[p][x];
        cnt[p] += c;
    }
    return;
}
int query(int u) {
    int res = 0, p = 0;
    for(int i = 30; i >= 0; i --) {
        int x = u >> i & 1, temp = !x;
        if(cnt[son[p][temp]] > 0) {
            res |= (temp << i);
            p = son[p][temp];
        }
        else {
            res |= (x << i);
            p = son[p][x];
        }
    }
    return res ^ u;
}
int main() {
    n = read(), m = read();
    for(int i = 1; i <= n; i ++) {
        int x = read();
        sum[i] = sum[i - 1] ^ x;
    }
    insert(sum[0], 1);
    for(int i = 1; i <= n; i ++) {
        if(i > m) {
            insert(sum[i - m - 1], -1);
        }
        ans = max(ans, query(sum[i]));
        insert(sum[i], 1);
    }
    printf("%d", ans);
    return 0;
}