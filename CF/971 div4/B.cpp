#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int N = 500 + 10;
int t, n, cnt;
char s[N][5];
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			cin >> s[i];
		}
		for(int i = n; i >= 1; i --) {
			for(int j = 3; j >= 0; j --) {
				if(s[i][j] == '#') {
					printf("%d ", j + 1);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

