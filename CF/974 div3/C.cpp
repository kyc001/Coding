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
long long t, n, a[N];
long long sum, ans;
long long Max(long long a, long long b) {
	return a > b ? a : b;
}
void solve() {
	n = read(),  sum = 0, ans = 0;
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
		sum += a[i];
	}
	if(n == 1 || n == 2) {
		printf("-1\n");
		return;
	}
	sort(a + 1, a + 1 + n);
	if(n % 2) {
		ans = 2 * n * a[(n + 1) / 2] - sum + 1;
	}
	else {
		ans = 2 * n * a[n / 2 + 1] - sum + 1;
	}
	printf("%lld\n", Max(ans, 0));
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

