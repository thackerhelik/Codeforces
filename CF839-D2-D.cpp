/*
for a number i we calculate the number of numbers divisible by i. Let it be cnt[i]
The answer would be i * (cnt[i] * ( 2 ^ (cnt[i] - 1) ))
how ? We have
(1 + x) ^ n = nC0 + nC1x + nC2x^2 + nC3x^3 + ....
differentiate with respect to x
n * (1 + x) ^ (n - 1) = nC1.1 + nC2.2.x + nC3.3.x.x + ...
put x = 1 we get
n * (2)^(n-1) = nC1.1 + nC2.2 + nC3.3 + ... which is the value we require. Multiply by i to get answer for i
lets skip multiplying by i at first. (because we are counting the values for 2*i and 4*i whose gcd is 2*i and not i)
so we have to remove the answers for 2*i 3*i 4*i .... from the ans[i] Note: we have to calculate answer from right
finally the answer is sum of all i*ans[i] from 1 to maxval
Complexity: n(1/2 + 1/3 + 1/4 + ...)
            nlogn
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int ll;

const ll mod=1000000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a-=b;if(a<0)a+=mod;return a;}

const ll MAXN = 200005;
const ll MAXVAL = 1000005;
ll a[MAXN];
map<ll,ll>m;

vector<ll>adj[MAXVAL];

ll ans[MAXVAL];
ll cnt1[MAXVAL];
ll cnt2[MAXVAL];

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    ll i, j;

    ll n;
    cin >> n;

    for(i = 0; i < n; ++i){
    	cin >> a[i];
    	cnt1[a[i]]++;
    }        

    for(i = 1; i < MAXVAL; ++i){
    	for(j = i; j < MAXVAL; j += i){
    		cnt2[i] += cnt1[j]; 
    	}
    }

    for(i = MAXVAL - 1; i >= 2; --i){
    	ll temp = 0LL;

    	if(cnt2[i] == 0)continue;
		else temp = mul(cnt2[i], powmod(2, cnt2[i] - 1));


		for(j = 2LL*i; j < MAXVAL; j += i){
    		temp = (temp + mod - ans[j])%mod;
    	}   

    	ans[i] = temp % mod;

    }


    ll finalans = 0;
    for(i = 2; i < MAXVAL; ++i){
    	finalans = add(finalans, mul(i, ans[i]));
    }

    cout << finalans << endl;

    return 0;
}

