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
/*一个奇数列，找到某种分法，
使得每个子列的中位数组成的数列的中位数是k
*/ 
/*15 10
1-9 5
10 10
11-15 13
*/
int t, n, k;
void solve() {
	n = read(), k = read();
	if(k == (n + 1)/2) {
		printf("1\n1\n");
		return;
	}
	else if(k == 1 || k == n) {
		printf("-1\n");
		return;
	}
	if(k % 2)
		printf("3\n%d %d %d\n", 1, k - 1, k + 2);
	else
		printf("3\n%d %d %d\n", 1, k, k + 1);
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


