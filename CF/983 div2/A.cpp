#include<bits/stdc++.h>
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
int t, n, a, b, temp, minn, maxx;
void solve() {
	n = read();
	a = 0, b = 0;
	for(int i = 1; i <= n * 2; i ++) {
		temp = read();
		a = a + (temp ^ 1); // a 0
		b = b + (temp ^ 0);// b 1
	}
	if(!(b%2)) {
		minn = 0;
		maxx = min(a, b);
	}
	else {
		minn = 1; 
		maxx = min(a, b);
	}
	printf("%d %d\n", minn, maxx);
	return;
}
int main() {
	t = read();
	while(t --) {
		solve();
	}
	return 0;
}


