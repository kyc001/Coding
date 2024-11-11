#include<bits/stdc++.h>
using namespace std;
struct Pet{
	int x;
	int nxt;
}pet[210];
int m, tag, cnt, h1=-1, h2=-1, p1, p2;
void init() {
	for(int i = 0; i <= 210; i ++) {
		pet[i].x = 0;
		pet[i].nxt = -1;
	}
	return;
}
void solve() {
	if(tag >= 100 || tag <= -100) return;
	if(m == 1) {
		pet[++ cnt].x = tag;
		if(tag > 0) {
			if(h1!=-1) pet[p1].nxt = cnt;
			if(h1==-1) h1 = cnt;
			p1 = cnt;
		}
		if(tag < 0) {
			if(h2!=-1) pet[p2].nxt = cnt;
			if(h2==-1) h2 = cnt;
			p2 = cnt;
		}
		return;
	}
	if(m == 2) {
		if(tag == 0) {
			if(h1 == -1 && h2 == -1) return; 
			if((h1 < h2 && h1 != -1) || h2==-1) {
				cout << pet[h1].x << " ";
				h1 = pet[h1].nxt;
				return;
			}
			if((h2 < h1 && h2 != -1) || h1==-1) {
				cout << pet[h2].x << " ";
				h2 = pet[h2].nxt;
				return;
			}
			return;
		}
		if(tag == 1) {
			if(h1!=-1) {
				cout << pet[h1].x << " ";
				h1 = pet[h1].nxt;
			}
			return;
		}
		if(tag == -1) {
			if(h2!=-1) {
				cout << pet[h2].x << " ";
				h2 = pet[h2].nxt;
			}
			return;
		}
		return;
	}
	return;
}
int main() {
	init();
	while(cin >> m >> tag) {solve();}
	return 0;
}
