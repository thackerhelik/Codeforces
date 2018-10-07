/*input
We use counting sort.
But answering queries is slow.
So we build 26 segment trees, one for each character.
Then we can update for corresponding characters.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, q;
char s[MAXN];

struct node{
	int val;
	int lazy;
};

struct node st[4*MAXN][27]; //26 segment trees

void build(int node, int be, int en){
	if(be == en){
		st[node][s[be]-'a'].val = 1;
		for(int i = 0; i < 26; ++i)
			st[node][i].lazy = -1;
		return;
	}
	int mid = (be + en) >> 1;
	build(2*node, be, mid);
	build(2*node + 1, mid + 1, en);
	for(int i = 0; i < 26; ++i){
		st[node][i].val = st[2*node][i].val + st[2*node+1][i].val;
		st[node][i].lazy = -1;
	}
}

int query(int node, int be, int en, int l, int r, int konsa){
	if(st[node][konsa].lazy != -1){
		st[node][konsa].val = st[node][konsa].lazy*(en - be + 1);
		if(be != en){
			st[2*node][konsa].lazy = st[node][konsa].lazy;
			st[2*node+1][konsa].lazy = st[node][konsa].lazy;
		}
		st[node][konsa].lazy = -1;
	}
	if(be > r || en < l)return 0;
	if(be >= l && en <= r)return st[node][konsa].val;
	int mid = (be + en) >> 1;
	int p1 = query(2*node, be, mid, l, r, konsa);
	int p2 = query(2*node + 1, mid + 1, en, l, r, konsa);
	return (p1 + p2);
}

void update(int node, int be, int en, int l, int r, int val, int konsa){
	if(st[node][konsa].lazy != -1){
		st[node][konsa].val = st[node][konsa].lazy*(en - be + 1);
		if(be != en){
			st[2*node][konsa].lazy = st[node][konsa].lazy;
			st[2*node+1][konsa].lazy = st[node][konsa].lazy;
		}
		st[node][konsa].lazy = -1;
	}
	if(be > r || en < l)return;
	if(be >= l && en <= r){
		st[node][konsa].val = val*(en - be + 1);
		if(be != en){
			st[2*node][konsa].lazy = val;
			st[2*node+1][konsa].lazy = val;
		}
		return;
	}
	int mid = (be + en) >> 1;
	update(2*node, be, mid, l, r, val, konsa);
	update(2*node + 1, mid + 1, en, l, r, val, konsa);
	st[node][konsa].val = st[2*node][konsa].val + st[2*node+1][konsa].val;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int x, y, type;
	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
		cin >> s[i];

	build(1, 1, n);

	for(int t = 0; t < q; ++t){
		int ct[30] = {0};
		cin >> x >> y >> type;
		if(type == 0){
			for(int i = 0; i < 26; ++i){
				ct[i] = query(1, 1, n, x, y, i);
			}
			int cur = y;
			for(int i = 0; i < 26; ++i){
				if(ct[i] == 0)continue;
				update(1, 1, n, x, y, 0, i);
				update(1, 1, n, cur - ct[i] + 1, cur, 1, i);
				cur = cur - ct[i];
			}
		}
		else{
			for(int i = 0; i < 26; ++i){
				ct[i] = query(1, 1, n, x, y, i);
			}
			int cur = x;
			for(int i = 0; i < 26; ++i){
				if(ct[i] == 0)continue;
				update(1, 1, n, x, y, 0, i);
				update(1, 1, n, cur, cur + ct[i] - 1, 1, i);
				cur = cur + ct[i];
			}
		}
    
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 26; ++j){
			if(query(1, 1, n, i, i, j)){
				cout << char(j+'a');
				break;
			}
		}
	}
	cout << endl;

	return 0;
}
