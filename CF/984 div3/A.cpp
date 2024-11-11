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
int t, n, a[55], diff, tag; 
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		n = read();
		tag = 1;
		for(int i = 1; i <= n; i ++)
			a[i] = read();
		for(int i = 2; i <= n; i ++) {
			diff = abs(a[i] - a[i - 1]);
			if(diff != 5 && diff != 7)	{
				tag = 0;
				break;
			}
		}
		if(tag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}


