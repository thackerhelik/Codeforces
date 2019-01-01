/*
First the 2 dimension are independent. Now Consider only one dimension. Say we have n. Considering both left and right boundaries
we have to place 2k boundaries from [1 to n - 1]. To do this we have (n-1)C2k ways. Similarly for the other dimnension
we have (m-1)C2k ways. Multiply them to get the answer.
*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;
const ll mod=1000000007;

ll pascal[2005][2005];
ll n, m, k;

void ncr(){
	ll i, j;
	pascal[0][0] = 1LL;
	for(i = 1; i < 2005; ++i){
		pascal[i][0] = 1LL;
		for(j = 1; j < 2005; ++j){
			pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % mod;
		}
	}
	return;
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    ncr();

    cin >> n >> m >> k;

    ll ans = 1LL;

 		ans = (pascal[n-1][2*k]*pascal[m-1][2*k])%mod;


 	cout << ans << endl;

    return 0;
}

