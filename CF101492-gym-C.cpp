/*
We first find out for each position the previous position which is coprime with it. If not there make some negative value.
Now it is simple range max query from l to r.
To find the previous position coprime for position i do:
1. Notice that maximum number of primes is 7
2. We find all the square free divisors of the number and its parity
3. Binary search from 0 to i - 1
4.  for all square free divisors find count = i - (leftmost position which has that divisor as factor)
    if parity is even then add count else subtract count
5. if coprime >= 1 then we have to search for mid + 1 to i
6. else we do search from lo to mid - 1

After we get the previous coprime array then it is just range max query for each query.
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;

const ll inf = 1e9;

const int MAXN = 50001;
int a[MAXN], pre[500005];
int parity[500005];
int previous_coprime[MAXN];
int n, q;
vector<int>prime_position[500005];
int st[4*MAXN];

void build(int node, int be, int en){
	if(be == en){
		st[node] = previous_coprime[be];
		return;
	}
	int mid = (be + en) >> 1;
	build(2*node, be, mid);
	build(2*node + 1, mid + 1, en);
	st[node] = max(st[2*node], st[2*node+1]);
}

int query(int node, int be, int en, int l, int r){
	if(l <= be && en <= r){
		return st[node];
	}
	if(r < be || l > en){
		return -1000000000;
	}
	int mid = (be + en) >> 1;
	int p1 = query(2*node, be, mid, l, r);
	int p2 = query(2*node + 1, mid + 1, en, l, r);
	return max(p1, p2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    int i, j;

 	cin >> n >> q;
 	for(i = 0; i < n; ++i)
 		cin >> a[i];           

 	for(i = 0; i < n; ++i){
 		vector<int>prime_divisors;
 		vector<int>sub_divisors;
 		int x = a[i];
 		for(j = 2; j*1LL*j <= x; j++){
 			if(x % j == 0){
 				prime_divisors.push_back(j);
 				while(x % j == 0)
 					x /= j;
 			}
 		}
 		if(x > 1)
 			prime_divisors.push_back(x);


 		for(int mask = 1; mask < (1 << sz(prime_divisors)); ++mask){
 			int num = 1;
 			for(j = 0; j < sz(prime_divisors); ++j){
 				if(mask & (1 << j)){
 					num = num * prime_divisors[j];
 				}
 			}
 			parity[num] = (__builtin_popcount(mask)) % 2;
 			sub_divisors.push_back(num);
 		}

 		int lo = 0, hi = i - 1;
 		int res = -inf;

 		while(lo <= hi){
 			int mid = (lo + hi) >> 1;
 			int coprime_count = i - mid;

 			for(auto div: sub_divisors){
 				if(sz(prime_position[div]) == 0)continue;
 				vector<int>::iterator it = lower_bound(all(prime_position[div]), mid);
 				int l = int(it - prime_position[div].begin());
 				int r = sz(prime_position[div]);
 				int cnt = r - l;
 				if(parity[div])
 					coprime_count -= cnt;
 				else
 					coprime_count += cnt;
 			}

 			if(coprime_count >= 1){
 				res = mid;
 				lo = mid + 1;
 			}
 			else{
 				hi = mid - 1;
 			}

 		}

 		previous_coprime[i] = res;

 		for(int mask = 1; mask < (1 << sz(prime_divisors)); ++mask){
 			int num = 1;
 			for(j = 0; j < sz(prime_divisors); ++j){
 				if(mask & (1 << j)){
 					num = num * prime_divisors[j];
 				}
 			}
 			prime_position[num].push_back(i);
 		}
 	}

 	build(1, 0, n - 1);

 	while(q--){
 		int l, r;
 		cin >> l >> r;
 		l--; r--;
 		int ret = query(1, 0, n - 1, l, r);
 		if(ret >= l)cout << "S" << endl;
 		else cout << "N" << endl;
 	}

    return 0;
}

