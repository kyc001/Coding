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
const int N = 2e5 + 10;
int t, n, a[N], fa[N], cnt;
bool vis[N];
string s;
int ff(int u) {
	if(fa[u]!=-1) return fa[u];
	else {
		if(vis[a[u]]==0 && a[u] != u) {
			vis[a[u]] = 1;
			cnt += s[u-1] == '0';
			return fa[u] = ff(a[u]);
		}
		else {
			cnt += s[u-1] == '0';
			return fa[u] = cnt;
		}
	}
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		n = read();
		memset(a, 0, sizeof(a));
		memset(fa, -1, sizeof(fa));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i ++) {
			a[i] = read();
		}
		cin >> s;
		for(int i = 1; i <= n; i ++) {
			vis[i] = 1, cnt = 0;
			printf("%d ", ff(i));
		}
		cout << endl;
	}
	return 0;
}

