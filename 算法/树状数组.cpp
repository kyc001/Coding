#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
#define MAXN 500010
using namespace std;
typedef long long ll;

ll read()  // 快速读入，不是这篇文章的重点
{
    ll ans = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
ll tree[MAXN];
inline void update(ll i, ll x) {
    for(ll pos = i; pos < MAXN; pos += lowbit(pos)) tree[pos] += x;
}
inline ll query(int n) {
    ll ans = 0;
    for(ll pos = n; pos; pos -= lowbit(pos)) ans += tree[pos];
    return ans;
}
inline ll query(ll x, ll y) {
    return query(y) - query(x - 1);
}
int A[MAXN];  // 离散化后的数组
typedef struct {
    ll value, id;
} mypair;
mypair B[MAXN];  // 原始数组（同时存储id）
bool cmp(mypair x, mypair y) {
    if(x.value < y.value)
        return true;
    else if(x.value == y.value && x.id < y.id)
        return true;
    return false;
}
int main() {
    ll n = read(), sum = 0;
    for(int i = 1; i <= n; i++) {
        B[i].value = read();
        B[i].id = i;
    }
    sort(B + 1, B + n + 1, cmp);
    for(int i = 1; i <= n; i++) A[B[i].id] = i;
    for(int i = 1; i <= n; i++) {
        sum += query(A[i]);
        update(A[i], 1);
    }
    sum = n * (n - 1) / 2 - sum;
    printf("%lld\n", sum);
    return 0;
}