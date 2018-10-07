/*
If a number has 3 divisors it can be expressed in the form p2
If a number has 4 divisors it can be expressed in the form pq or p3
If a number has 5 divisors it can be expressed in the form p4
Now 3 and 5 divisors and 4 of the form p3 can be checked and put into a map with the count of primes
we are left with numbers of the form pq. For that we take the gcd of the pairs and since that number will be a prime, 
we push it into the map. Now we are left with numbers of form pq with no gcd in common with other numbers (also duplicates might be there
case is 2 10 10) but we know that they will contribute 2 prime numbers with count 1 so we can handle them separately.
*/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back

typedef long long int ll;

const ll mod = 998244353;


bool fourth(ll x){
	ll xx = (ll)round(sqrt(x));
	ll xxx = (ll)round(sqrt(xx));
	return (xxx*xxx*xxx*xxx == x);
}

bool third(ll x){
	ll xx = (ll)round(cbrt(x));
	return (xx*xx*xx == x);
}

bool second(ll x){
	ll xx = (ll)round(sqrt(x));
	return (xx*xx == x);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    ll n, x, i;
   	cin >> n;

   	set<ll>s;
   	map<ll,ll>m;
   	set<ll>posp;
   	map<ll,ll>rem;


   	vector<ll>st;

   	for(i = 0; i < n; ++i){
   		cin >> x;	
   		if(fourth(x)){
   			ll xx = (ll)round(sqrt(x));
   			ll xxx = (ll)round(sqrt(xx));
   			m[xxx]+=4;
   		}
   		else if(second(x)){
   			ll xx = (ll)round(sqrt(x));
   			m[xx]+=2;
   		}
   		else{
   			if(third(x)){
   				ll xx = (ll)round(cbrt(x));
   				m[xx]+=3;
   			}
   			else{
   				st.pb(x);
   			}
   		}
   	}        


   	for(auto it: m){
   		posp.insert(it.fi);
   	}


   	for(auto it: st){
   		for(auto it2: st){
   			if(it < it2){
   				ll g = __gcd(it, it2);
   				if(g != 1)posp.insert(g);
   			}
   		}
   	}

   	for(auto it: st){
   		bool suc = 0;
   		for(auto it2: posp){
   			if(it % it2 == 0){
   				m[it2]++;
   				m[it/it2]++;
   				suc = 1;
   				break;
   			}
   		}
   		if(!suc)rem[it]++;
   	}


   	ll ans = 1;

   	for(auto it: m){
   		ans = ans*(it.se+1);
   		ans = ans % mod;
   	}

   	for(auto it: rem){
   		ans = ans *	(it.se + 1) * (it.se + 1);
   		ans = ans % mod;
   	}

   	cout << ans << endl;

    return 0;
}

