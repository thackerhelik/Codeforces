/*
find the indices with l[idx] = 0 and r[idx] = 0 
this is the maximum. assign all such indices with max possible.
then adjust the others accordingly
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define yolo "debug_statement"

typedef long long int ll;

bool used[1005];
int l[1005];
int r[1005];
int ans[1005];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

	int i, n;
	cin >> n;
	int ct = n;

	for(i = 0; i < n; ++i)cin >> l[i];
	for(i = 0; i < n; ++i)cin >> r[i];

	for(i = 0; i < n; ++i)
		ans[i] = -1;

	for(int it = 0; it < n; ++it){
		
		bool idx[n+5] = {false};

		for(i = 0; i < n; ++i)
			idx[i] = false;

		for(i = 0; i < n; ++i){
			if(!used[i] && l[i] == 0 && r[i] == 0)
				idx[i] = true;
		}


		int howmanytrue = 0;
		int left = 0;

		for(i = 0; i < n; ++i){
			if(used[i] == true)continue;
			if(idx[i] == true)howmanytrue++;
			left++;
		}

		for(i = 0; i < n; ++i){
			if(idx[i] == true){
				used[i] = true;
				ans[i] = ct;
			}
		}	

		// int ctr = 0;
		int lefts = 0;
		for(i = 0; i < n; ++i){
			if(idx[i] == true){
				lefts++;
			}
			else{
				l[i] = l[i] - lefts;
			}
		}

		int rights = 0;
		for(i = n - 1; i >= 0; --i){
			if(idx[i] == true){
				rights++;
			}
			else{
				r[i] = r[i] - rights;
			}
		}

		ct--;

	}

	for(i = 0; i < n; ++i){
		if(ans[i] == -1 || ans[i] <= 0 || ans[i] > n){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	for(i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;

    return 0;
}
