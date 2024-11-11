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
const int N = 1e5 + 10;
int n, k, a[N], maxn;
int b[N][32];
vector<int> sum;
map<vector<int>, int> ma;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= k; i ++)
		sum.push_back(0);
	ma[sum] = 0;
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
		sum.clear();
		for(int j = 0; j < k; j ++) {
			if((1 << j) & a[i])
				b[i][j] = b[i - 1][j] + 1;
			else
				b[i][j] = b[i - 1][j];
			sum.push_back(b[i][j] - b[i][0]);
		}
		if(ma.count(sum)) {
			if(maxn < i - ma[sum]) {
				maxn = i - ma[sum];
			}
		}
		else ma[sum] = i;
	}
	printf("%d", maxn);
	return 0;
}

