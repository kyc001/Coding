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
int t, l, r;
int ans;
void sol(int s) {
	for(int i = sqrt(s); i * (i + 1) / 2 <= s; i ++) {
		if((i + 1) * (i + 2) / 2 > s) {
			ans = i;
			return;
		}
	}
} 
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		l = read(), r = read();
		if(l == r) {
			printf("%d\n", 1);
			continue;
		}
		ans=0;
		sol(r - l);
		printf("%d\n", ans+1);
	} 
	return 0;
}

