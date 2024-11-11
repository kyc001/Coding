#include<bits/stdc++.h>
#define ri register int
using namespace std;
int t, n, cnt;
string s;
int check(int n) {
	return double(sqrt(n) * sqrt(n)) == n;
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("%d", &t);
	while(t --) {
		cin >> n >> s;
		cnt = 0;
		if(check(n)) {
			for(int i = 0; i < s.size(); i ++) {
				if(s[i] == '0') cnt ++;
			}
			if(cnt == (sqrt(n)-2)*(sqrt(n)-2)) printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	} 
	return 0;
}

