/*
put everything into a vector pair where first value is the time second is 0 if entry else 1 if exit
now iterate through the vector and binary search the other end for the number of people
for checking number of persons in the desired range use prefix sums
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)
#define rep(i,a,b) for(i=a;i<=b;++i)
#define per(i,a,b) for(i=b;i>=a;--i)

#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define popcll(a) __builtin_popcountll(a) //count set bits for long long int

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define yolo "debug_statement"

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi=acos(-1);
const ll mod=1000000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a-=b;if(a<0)a+=mod;return a;}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

	ll i, j, t, n, k, x, y;
	vector<pair<ll,ll>>v;
	cin >> t;
	for(ll te = 1; te <= t; ++te){
		cout << "Case " << te << ": ";
		v.clear();
		cin >> n >> k;
		ll finalans;

		ll mini = 10000000000000000;
		ll maxi = -1;

		for(i = 0; i < n; ++i){
			cin >> x >> y;
			mini = min(mini, x);
			maxi = max(maxi, y);
			v.push_back({x, 0});
			v.push_back({y, 1});
		}
		
		finalans = maxi - mini;

		sort(all(v));
		
		ll arr[2*n] = {0};
		ll arren[2*n] = {0};

		for(i = 0; i < 2*n; ++i)
			arr[i] = arren[i] = 0;

		for(i = 0; i < 2*n; ++i)
			if(v[i].se == 0)
				arr[i] = 1;
			else 
				arren[i] = 1;

		for(i = 1; i < 2*n; ++i){
			arr[i] += arr[i - 1];
			arren[i] += arren[i - 1];
		}

		for(i = 0; i < 2*n; ++i){
			
			ll lo = i, hi = 2*n - 1;
			ll res = -1;
			ll mid;
			
			while(lo <= hi){
				ll kitne = 0;
				mid = (lo + hi) >> 1;
				
				if(i > 0)
					kitne = (arr[i - 1] - arren[i - 1]) + (arr[mid] - arr[i - 1]);
				else
					kitne = (arr[mid]);


				// cout << i << " " << mid << " "  << kitne << endl;

				if(kitne >= k){
					res = mid;
					hi = mid - 1;
				}
				else{
					lo = mid + 1;
				}

			}

			if(res != -1){
				// cout << res << " " << i << " " << arr[i] << " " << arr[res] << endl;
				finalans = min(finalans, v[res].fi - v[i].fi);
			}

		}


		cout << finalans << endl;
	}          

    return 0;
}

