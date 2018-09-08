/*input
generate all possible values
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;


ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}


vector<ll>ans;
string s;

ll lowfind(ll x){
	ll lo = 0, hi = sz(ans), mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(ans[mid] > x){
			hi = mid - 1;
		}
		else if(ans[mid] == x){
			// res = mid;
			hi = mid - 1;
		}
		else{
			res = mid;
			lo = mid + 1;
		}
	}
	return res;
}

ll hifind(ll x){
	ll lo = 0, hi = sz(ans), mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(ans[mid] > x){
			hi = mid - 1;
		}
		else{
			res = mid;
			lo = mid + 1;
		}
	}
	return res;
}

void gen(int len, int cur, int ct){
	if(cur >= len){
		if(ct > 3)return;
		ans.pb(stoll(s));
		return;
	}
	if(ct < 3){
		s.pb('0');
		gen(len, cur + 1, ct);
		s = s.substr(0, sz(s) - 1);
		for(int i = 1; i < 10; ++i){
			s.pb(i + '0');
			gen(len, cur + 1, ct + 1);
			s = s.substr(0, sz(s) - 1);
		}
	}
	else{
		s.pb('0');
		gen(len, cur + 1, ct);
		s = s.substr(0, sz(s) - 1);
	}
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    ans.pb(0);

	for(int i = 1; i <= 18; ++i){
		for(int j = 1; j <= 9; ++j){
			s = "";
			s.pb(j + '0');
			gen(i, 1, 1);
		}
	}            

    ans.pb(1000000000000000000);
    ans.pb(1000000000000000001);

	ll l, r, q;
	cin >> q;

	while(q--){
		cin >> l >> r;
		ll x = lowfind(l);
		ll y = hifind(r);
		cout << y - x << endl;
	}

    return 0;
}
