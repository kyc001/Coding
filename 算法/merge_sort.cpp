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
const int N = 5000000 + 10; 
int n, k, a[N], mid, b[N];
void Sort(int st, int en) {
	if(st < en) {
		int mid = (st + en) / 2;
		Sort(st, mid);
		Sort(mid + 1, en);
		int p1=st, p2=mid+1, p=0;
		while((p1 <= mid) && (p2 <= en)) {
			if(a[p1] <= a[p2])
				b[++ p] = a[p1 ++];
			else
				b[++ p] = a[p2 ++];
		}
		while(p1 <= mid) b[++ p] = a[p1 ++];
		while(p2 <= en) b[++ p] = a[p2 ++];
		for(int i = st; i <= en; i ++)
			a[i] = b[i - st + 1];
	}
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	Sort(1, n);
	printf("%d ", a[k + 1]);
	return 0;
}

