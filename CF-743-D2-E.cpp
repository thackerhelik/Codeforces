/*
First we have a nxt[color][idx][length] array which signifies for a color c at index i where is the length element located.
If not there let it be -1
Now we binary search for len since if it is possible for len we know it has to be possible for len - 1, len - 2, ...
For checking each we have to have a bitmask dp which calculates the number of len + 1 elements (So final answer becomes len*8 + dp_ans)
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define fi first
#define se second

int n;
int a[1005];
int dp[1005][(1<<8)+1];
int nxt[9][1005][1005];
int X;

int solve(int idx, int mask){
	if(mask == (1 << 8) - 1)return 0;
	if(dp[idx][mask] != -1)return dp[idx][mask];
	int &ans = dp[idx][mask];

	ans = -100000000;
	for(int i = 0; i < 8; ++i){
		if(mask & (1 << i))continue;
		int pos1 = nxt[i][idx][X];
		if(pos1 != -1)
			ans = max(ans, solve(pos1 + 1, mask | (1 << i)));
		int pos2 = nxt[i][idx][X+1];
		if(pos2 != -1)
			ans = max(ans, 1 + solve(pos2 + 1, mask | (1 << i)));
	}

	return ans;
}

bool possible(){
	memset(dp, -1, sizeof(dp));
	if(solve(0, 0) < 0)return false;
	else return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    set<int>s;

    int i, j, k;
    cin >> n;
    fo(i, n){
    	cin >> a[i];
    	a[i]--;
    	s.insert(a[i]);
    }

    for(i = 0; i < 8; ++i){
    	for(k = 0; k < 1005; ++k){
			for(j = 0; j < 1005; ++j)
	    		nxt[i][j][k] = -1;
    	}
    }

    for(i = n - 1; i >= 0; --i){
    	for(j = 0; j < 8; ++j){
    		if(a[i] == j)nxt[j][i][1] = i;
    		else nxt[j][i][1] = nxt[j][i+1][1];
    		for(k = 2; k < 1005; ++k){
    			if(a[i] == j)nxt[j][i][k] = nxt[j][i+1][k-1];
    			else nxt[j][i][k] = nxt[j][i+1][k];
    		}
    	}
    }

    int best = 0;
    int lo = 1, hi = n;
    while(lo <= hi){
    	int mid = (lo + hi) >> 1;
    	X = mid;

    	if(possible()){
    		best = mid;
    		lo = mid + 1;
    	}
    	else{
    		hi = mid - 1;
    	}
    }

    int ans = (int)s.size();


	if(best > 0){            	
		memset(dp, -1, sizeof(dp));
    	X = best;
		ans = 8 * X + solve(0, 0);
	}

	cout << ans << endl;

    return 0;
}

