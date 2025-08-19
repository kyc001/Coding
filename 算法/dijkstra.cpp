#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int read() {
	int sum = 0, f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		if(c == '-')	f = -f;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		sum = (sum << 3) + (sum << 1) + c - 48;
		c = getchar();
	}
	return sum * f;
}
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int inf = 1e9 + 10;
int n, m, s;
int dis[N], vis[N];
struct Node{
	int to;
	int d;
	inline bool operator < (const Node& b) const{
		return d>b.d;
	}
};
vector<Node> g[N];
priority_queue<Node> q;
void dijkstra() {
	dis[s] = 0;
	q.push({s, 0});
	while(!q.empty()) {
		Node cur = q.top();
		q.pop();
		int u = cur.to, cost = cur.d;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < g[u].size(); i ++) {
			int y = g[u][i].to, z = g[u][i].d;
			if(dis[y] > cost + z) {
				dis[y] = cost + z;
				q.push({y, dis[y]});
			}
		}
	}
}
void solve() {
    for (int i = 1; i <= n; i ++) {
        dis[i] = inf;
    }
    for (int i = 1; i <= m; i++)    {
        int x = read(), y = read(), z = read();
        g[x].push_back({y, z});
    }
	dijkstra();
	for(int i = 1; i <= n; i ++) {
		printf("%d ", dis[i]);
	}
} 
int main() {
	// freopen("P4779.in", "r", stdin);
	// freopen(".out", "w", stdout);
	n = read(), m = read(), s = read();
	solve();
	return 0;
}

