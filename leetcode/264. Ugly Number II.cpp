#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
int n, cnt;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n;
	q.push(1);
	while(!q.empty()) {
		long long a = q.top();
		q.pop();
		cnt ++;
		if(cnt == n) {
			cout << a << endl;
			break; 
		}
		cout << a << endl;
		q.push(a * 2); q.push(a * 3); q.push(a * 5);
	}
	return 0;
}


