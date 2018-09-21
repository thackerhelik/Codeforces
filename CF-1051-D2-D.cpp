/*
Simple DP
since it is 2*n matrix we can place in a column (0,0) or (0,1) or (1,0) or (1,1) and compute accordingly.
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;

const ll mod=998244353;

ll n, k;

ll dp[1005][3][3][2005];

void init(){
	int i, j, kk, l;
	fo(i, 1005)fo(j, 3)fo(kk, 3)fo(l, 2005)dp[i][j][kk][l] = -1;
}

ll solve(ll cur, ll prev1, ll prev2, ll comp){

	if(cur >= n){
		if(comp == k)return 1;
		else return 0;
	}
		
	if(dp[cur][prev1][prev2][comp] != -1)return dp[cur][prev1][prev2][comp];

	ll ans = 0;

	if(prev1 == 0 && prev2 == 0){
		ans = (ans + solve(cur + 1, 0, 0, comp));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 0, 1, comp + 1));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 0, comp + 1));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 1, comp + 1));
		if(ans >= mod)ans %= mod;
	}	
	else if(prev1 == 0 && prev2 == 1){
		ans = (ans + solve(cur + 1, 0, 0, comp));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 0, 1, comp));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 0, comp + 2));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 1, comp));
		if(ans >= mod)ans %= mod;
	}
	else if(prev1 == 1 && prev2 == 0){
		ans = (ans + solve(cur + 1, 0, 0, comp));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 0, 1, comp + 2));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 0, comp));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 1, comp));
		if(ans >= mod)ans %= mod;
	}
	else{
		ans = (ans + solve(cur + 1, 0, 0, comp + 1));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 0, 1, comp + 1));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 0, comp + 1));
		if(ans >= mod)ans %= mod;
		ans = (ans + solve(cur + 1, 1, 1, comp));
		if(ans >= mod)ans %= mod;
	}

	return dp[cur][prev1][prev2][comp] = ans%mod;
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif


    init();
    cin >> n >> k;

    ll ans = (solve(1, 0, 0, 1))%mod;
    ans = (ans + solve(1, 0, 1, 2))%mod;    
    ans = (ans + solve(1, 1, 0, 2))%mod;    
    ans = (ans + solve(1, 1, 1, 1))%mod;

    ans = ans % mod;

    cout << ans << endl;    

    //#if !ONLINE_JUDGE
    //    cout << fixed << setprecision(12) << "-------------------------------------------------\n";
    //    cout << double(clock())/CLOCKS_PER_SEC << " seconds" << endl;
    //#endif
    return 0;
}
