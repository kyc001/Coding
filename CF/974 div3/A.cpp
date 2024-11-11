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
int t, n, k, temp, ans, cnt;
void solve() {
	n = read(), k = read(), ans = 0, cnt = 0;
	for(int i = 1; i <= n; i ++) {
		temp = read();
		if(temp >= k) {
			ans += temp;
		}
		else if(ans && temp == 0) ans --, cnt ++;
	}
	return;
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		solve();
		printf("%d\n", cnt);
	}
	return 0;
}

