#include<bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
inline ll read() {
	ll sum = 0, f = 1;
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
const ll MOD = 1e9 + 7;
const int N = 2e5 + 10;
ll t, n, a[N], sum, P, Q; 
ll qpow(ll a,ll n) {
	ll ans = 1;
	while(n) {
		if(n&1) ans=ans*a%MOD;
		a = a*a % MOD;
		n = n >> 1;
	}
	return ans % MOD;
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	t = read();
	while(t --) {
		n = read();
		sum = 0, P = 0, Q = 0;
		for(int i = 1; i <= n; i ++) {
			a[i] = read() % MOD;
			sum = (sum + a[i])%MOD;
		} 
		for(int i = 1; i <= n; i ++) {
			sum = (sum - a[i] + MOD)%MOD;
			P = (P + (a[i] * (sum % MOD))%MOD) % MOD; 
		}
		Q = 1ll * n * (n - 1) / 2 % MOD;
		printf("%lld\n", (P%MOD)*(qpow(Q, MOD-2)%MOD)%MOD);
	}
	return 0;
}


