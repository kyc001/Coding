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
struct Node{
    int to, dis;
};
vector<Node> g[N];
int n, sum[N];
void dfs(int x, int fa) {
    for(int i = 0; i < g[x].size(); i ++) {
        int v = g[x][i].to, w = g[x][i].dis;
        if(v != fa) {
            sum[v] = sum[x] ^ w;
            dfs(v, x);
        }
    }
}
int trie[N*32][2], tot;//一共n个数，每个数最多新开32位的路径
int ans;
void build(int val) {
    int p = 0;
    for(int i = (1 << 30); i; i >>= 1) {
        bool c = val & i;
        if(!trie[p][c]) trie[p][c] = ++ tot;
        p = trie[p][c]; 
    }
    return;
}
int query(int val) {
    int temp = 0, p = 0;
    for(int i = (1 << 30); i; i >>= 1) {
        bool c = val & i;
        if(trie[p][!c]) {
            temp += i;
            p = trie[p][!c];
        }
        else p = trie[p][c];
    }
    return temp;
}
int main() {
    n = read();
    for(int i = 1; i < n; i ++) {
        int u = read(), v = read(), w = read();
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i ++) {
        build(sum[i]);
    }
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, query(sum[i]));
    }
    printf("%d\n", ans);
    return 0;
}