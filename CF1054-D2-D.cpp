/*
greedy algorithm works
build a prefix xor array P
have a map F which stores how many times a value has been seen
answer without complement allowed is n*(n+1)/2 - summation x : F[x]*(F[x]-1)/2 (for x = 0 we have ((F[0]+1)*(F[0]+1-1))/2)
now since a^2 + b^2 + c^2 + ... <= (a + b + c + ...)^2 greedy algorithm will give correct answer
for every value see if complement has less value then swap
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

typedef long long int ll;

const ll MAXN = 200005;

ll P[MAXN], arr[MAXN];
map<ll,ll>F;        

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    for(ll i = 0; i < n; ++i){
    	cin >> arr[i];
    }

    P[0] = arr[0];

    for(ll i = 1; i < n; ++i){
    	P[i] = P[i - 1] ^ arr[i];
    }

    F[0]++; //why

 	bool f = false;

    ll ans = 0;

    for(ll i = 0; i < n; ++i){
    	ll val = P[i];
    	ll complement = (1LL<<k) - val - 1;
    	if(f)swap(val, complement);
    	if(F[val] <= F[complement]){
    		F[val]++;
    	}
    	else{
    		F[complement]++;
    		f = f ^ 1;
    	}
    }

    ans = n*(n+1)*1LL/2;

    for(auto it: F){
    	if(it.se)
	    	ans = ans - (it.se*1LL*(it.se-1))/2;
    }

    cout << ans << endl;
    return 0;

}
