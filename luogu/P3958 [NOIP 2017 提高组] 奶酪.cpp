#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000 + 10;

int T;
int n;
ll h, r;
int fa[N], rk[N];

inline void init(int n) {
    for(int i = 1; i <= n; i ++) {
        fa[i] = i;
        rk[i] = 1;
    }
    fa[1001] = 1001; rk[1001] = 1;
    fa[1002] = 1002; rk[1002] = 1;
    return;
}

int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline void merge(int m, int n) {
    int x = find(m), y = find(n);
    if(rk[x] <= rk[y]) {
        fa[x] = y;
    }
    else {
        fa[y] = x;
    }
    if(rk[x] == rk[y] && x != y) {
        rk[x] ++;
    }
}

struct ball {
    ll x, y, z;
}t1, t2, a[N];

bool dist(ball b1, ball b2) {
    ll dis = (b1.x - b2.x) * (b1.x - b2.x) + (b1.y - b2.y) * (b1.y - b2.y) + (b1.z - b2.z) * (b1.z - b2.z);
    return dis <= 4*r*r;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> T;
    while(T --) {
        cin >> n >> h >> r;
        init(n);
        for(int i = 1; i <= n; i ++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            if(abs(a[i].z) <= r) merge(1001, i);
            if(abs(a[i].z - h) <= r) merge(1002, i);
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j < i; j ++) {
                if(dist(a[i], a[j]))
                    merge(i, j);
            }
        }
        if(find(1001) == find(1002)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}