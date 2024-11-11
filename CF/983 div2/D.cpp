#include<bits/stdc++.h>
using namespace std;
int ask(int x, int y) {
	cout << "?" << " " << x << " " << y << endl;
	fflush(stdout);
	int t; cin >> t;
	return t;
}
void solve() {
	int n, tag; cin >> n;
	vector<int> ans(n, 0);
	int l = 1, r = 2;
	for(;r < n; r ++) {
		int tag = ask(l, r);
		if(!tag) {
			ans[r] = 0;
		}
		else {
			ans[r] = 1;
			l ++, r ++;
			break;
		}
	}
	while(r < n) {
		if(r == n - 1 && l == n - 2) {
			ans[r] = 1;
			break;
		}
		tag = ask(l, r);
		if(!tag) {
			ans[r] = l;
			l ++, r ++;
		}
		else {
			l ++;
		}
	}
	cout << "!";
	for(int i = 1; i < n; i ++) {
		cerr << " " << ans[i];
	}
	cout << endl;
	fflush(stdout);
}
int T;
int main() {
	cin >> T; 
	while(T --) {
		solve();
	}
	return 0;
}


