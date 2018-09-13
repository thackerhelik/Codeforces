/*
take care that if gap exceeds 15 we can fit all previous anyway because 4^15 > 1e9
Fit as many as possible into the new and the remaining convert to big box size
*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

typedef long long int ll;


vector<pair<ll,ll>>v;
ll n;

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    ll x, y;

    cin >> n;

    for(ll i = 0; i < n; ++i){
    	cin >> x >> y;
    	v.pb({x, y});
    }        

    sort(all(v));

    ll ans = 0;

   	for(ll i = 1; i < n; ++i){
   		ll diff = 2LL * (v[i].fi - v[i - 1].fi);
   		ll prev = v[i - 1].se;
		if(diff >= 15)continue;
   		ll capacity = v[i].se * 1LL * (1LL << (diff));
   		if(prev <= capacity)continue;
   		prev -= capacity;
   		v[i].se += ( (prev + (1LL << diff) - 1) / (1LL << diff) );
   	}

   	for(ans = v[n - 1].fi + 1; ; ++ans){
   		ll p = 2LL * ( ans - v[n - 1].fi );
		if((1LL<<p) >= v[n - 1].se)
			break;
   	}

   	cout << ans << endl;

    return 0;
}
