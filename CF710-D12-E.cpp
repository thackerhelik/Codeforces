/*
only some cases are relevant
we cannot have delete more than 1 time in a row
and also if there are 2 copy operations add / remove can appear between them only once
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[20000005];
ll n, x, y;

int main(){
	cin >> n >> x >> y;
	for(int i = 0; i <= n; ++i){
		dp[i] = x*i;
	}
	for(int i = 1; i <= n; ++i){
		dp[2*i] = min(dp[2*i], dp[i] + y);
		dp[2*i-1] = min(dp[2*i-1], dp[i] + x + y);
		dp[2*i+1] = min(dp[2*i+1], dp[i] + x + y);
	}
	cout << dp[n] << endl;
	return 0;
}
