#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll sum = 0, f = 1;
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
const int N = 60;
ll n, p[60], ans;
void insert(int x) {
	for(int i = 50; i >= 0; i --) {
		if((x >> i) & 1) {
			if(!p[i]) {
				p[i] = x;
				break;
			}
			x ^= p[i];
		}
	}
	return;
}
void solve() {
	for(int i = 0; i <= 50; i ++)
		for(int j = 0; j < i; j ++)
			if(p[i] & (1LL << j)) p[i] ^= p[j];
	return;
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i ++) {
		int temp = read();
		insert(temp);
	}
	solve();
	for(int i = 0; i <= 50; i ++)
		ans ^= p[i];
	printf("%lld", ans);
	return 0;
}

