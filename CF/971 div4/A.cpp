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
int n, a, b;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	while(n --) {
		a = read(), b = read();
		printf("%d\n", b - a);
	}
	return 0;
}

