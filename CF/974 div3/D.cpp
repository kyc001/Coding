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
int t;
int n, d, k;
int l[N], r[N], st[N], fi[N], x, y;
int mom, bro, temp, a, b;
void solve() {
	n = read(), d = read(), k = read();
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	memset(st, 0, sizeof(st));
	memset(fi, 0, sizeof(fi));
	for(int i = 1; i <= k; i ++) {
		x = read(), y = read();
		l[x] ++, r[y] ++;
	}
	for(int i = 1; i <= n; i ++) {
		st[i] = st[i - 1] + l[i];
		fi[i] = fi[i - 1] + r[i];
	}
	mom = INT_MAX, bro = 0; 
	for(int i = 1; i <= n; i ++) {
		if(i + d - 1 <= n) {
			temp = st[i + d - 1] - fi[i - 1];
			if(temp < mom) {
				mom = temp, a = i;
			}
			if(temp > bro) {
				bro = temp, b = i;
			}
		}
	}
	printf("%d %d\n", b, a);
	return;
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		solve();
	}
	return 0;
}

