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
int t, n, k;
void solve() {
	n = read(), k = read();
	if(n % 2) {
		if(k % 4 == 3 || k % 4 == 0) printf("YES\n");
		else printf("NO\n");
	}
	else if(k % 4 == 1 || k % 4 == 0) printf("YES\n");
		else printf("NO\n");
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

