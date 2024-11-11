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
bool is(int x, int y, int z) {
	if(x + y > z && y + z > x && z + x > y)
		return true;
	else
		return false;
}
const int N = 2e5 + 10; 
int t, n, ans;
void solve() {
	n = read();
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		a[i] = read();
	sort(a.begin(), a.end());
	ans = 2e5 + 10;
	for(int i = 0; i < n - 2; i ++) {
        int id = lower_bound(a.begin(), a.end(), a[i] + a[i + 1]) - a.begin();
        ans = min(ans, i + n - id);
    }
	printf("%d\n", ans);
	return;
}
// i - 1 + n - (id - 1) 
/*
1 2 3 4 5 6 7
4 2 3 4 5 6 7
4 5 3 4 5 6 7
4 5 3 4 5 6 4

1 1 2 2 3 3 4 4 5 6 7  8  8  9  9
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
0 13
1 12
2 11
3 10
4 10
5 10
6 10
7 9
8 
*/
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		solve();
	}
	return 0;
}
