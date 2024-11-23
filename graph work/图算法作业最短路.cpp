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
int a[10][10]; 
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	for(int i = 1; i <= 6; i ++) {
		for(int j = 1; j <= 6; j ++) {
			a[i][j] = read();
		} 
	}
	for(int i = 1; i <= 6; i ++) {
		for(int j = i + 1; j <= 6; j ++) {
			for(int k = i + 1; k <= j; k ++) {
				if(a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];
			} 
		}
	}
	for(int i = 1; i <= 6; i ++) {
		cout << a[1][i] << " ";
	}
	return 0;
}


