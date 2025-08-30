#include <bits/stdc++.h>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll tree[N << 2], mark[N << 2][3];
ll n, q, m, a[N];
void push_down(ll p, ll len) {
    if(mark[p][1] != 1) {
        ll mul_tag = mark[p][1];
        tree[ls(p)] = (tree[ls(p)] * mul_tag) % m;
        mark[ls(p)][1] = (mark[ls(p)][1] * mul_tag) % m;
        mark[ls(p)][2] = (mark[ls(p)][2] * mul_tag) % m;
        tree[rs(p)] = (tree[rs(p)] * mul_tag) % m;
        mark[rs(p)][1] = (mark[rs(p)][1] * mul_tag) % m;
        mark[rs(p)][2] = (mark[rs(p)][2] * mul_tag) % m;
        mark[p][1] = 1;
    }
    if(mark[p][2] != 0) {
        ll add_tag = mark[p][2];
        ll left_len = len - (len >> 1);
        ll right_len = len >> 1;
        tree[ls(p)] = (tree[ls(p)] + add_tag * left_len) % m;
        mark[ls(p)][2] = (mark[ls(p)][2] + add_tag) % m;
        tree[rs(p)] = (tree[rs(p)] + add_tag * right_len) % m;
        mark[rs(p)][2] = (mark[rs(p)][2] + add_tag) % m;
        mark[p][2] = 0;
    }
}
void build(ll l = 1, ll r = n, ll p = 1) {
    mark[p][1] = 1;
    mark[p][2] = 0;
    if(l == r) {
        tree[p] = a[l] % m;
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, ls(p));
    build(mid + 1, r, rs(p));
    tree[p] = (tree[ls(p)] + tree[rs(p)]) % m;
}
void update(ll l, ll r, ll d, ll tag, ll p = 1, ll cl = 1, ll cr = n) {
    if(cr < l || cl > r)
        return;
    else if(cl >= l && cr <= r) {
        if(tag == 1) {
            tree[p] = (tree[p] * d) % m;
            mark[p][1] = (mark[p][1] * d) % m;
            mark[p][2] = (mark[p][2] * d) % m;
        } else {
            tree[p] = (tree[p] + (cr - cl + 1) * d) % m;
            mark[p][2] = (mark[p][2] + d) % m;
        }
        return;
    } else {
        ll mid = (cl + cr) >> 1;
        push_down(p, cr - cl + 1);
        update(l, r, d, tag, ls(p), cl, mid);
        update(l, r, d, tag, rs(p), mid + 1, cr);
        tree[p] = (tree[ls(p)] + tree[rs(p)]) % m;
    }
}
ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n) {
    if(cl > r || cr < l)
        return 0;
    else if(cl >= l && cr <= r)
        return tree[p];
    else {
        ll mid = (cl + cr) >> 1;
        push_down(p, cr - cl + 1);
        return (query(l, r, ls(p), cl, mid) + query(l, r, rs(p), mid + 1, cr)) % m;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build();
    for(int i = 1; i <= q; i++) {
        ll op, l, r;
        cin >> op >> l >> r;
        if(op == 3)
            cout << query(l, r) << '\n';
        else {
            ll d;
            cin >> d;
            update(l, r, d, op);
        }
    }
    return 0;
}