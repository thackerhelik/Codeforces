/*input
we can see that brute force is not O(n2) it is O(nlogn) because it is harmonic sum.
the ending states are losing obviously. Now we go from n to 1 and check the answer for each value.
if we can reach to a losing position in next move, that means by moving there we can win.
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()


int n;

int ans[100005];
int a[100005];
int pos[100005];
vector<int>adj[100005];

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

  int i;

	cin >> n;
	for(i = 0; i < n; ++i){
		cin >> a[i];
		pos[a[i]] = i;
	}            

	for(i = 0; i < n; ++i)ans[i] = -1;

	for(i = 0; i < n; ++i){
		int pos = i;
		int val = a[i];
		for(pos = i + a[i]; pos < n; pos = pos + a[i]){
			if(a[pos] > a[i]){
				adj[i].push_back(pos);
			}
		}
		for(pos = i - a[i]; pos >= 0; pos = pos - a[i]){
			if(a[pos] > a[i]){
				adj[i].push_back(pos);
			}
		}
	}

	for(i = 0; i < n; ++i){
		if(sz(adj[i]) == 0){
			ans[i] = 0;
		}
	}



	for(i = 0; i < n; ++i){
		if(sz(adj[i]) == 0)ans[i] = 0;
	}


	for(i = n - 1; i >= 0; --i){
		int tempi = pos[i];
		if(sz(adj[tempi]) == 0)continue;
		bool done = false;
		for(auto it: adj[tempi]){
			if(ans[it] == 0){
				ans[tempi] = 1;
				done = true;
				break;
			}
		}
		if(!done)ans[tempi] = 0;
	}


	for(i = 0; i < n; ++i){
		if(ans[i])cout << "A";
		else cout << "B";
	}
	cout << endl;


    return 0;
}

