/*input
Lets store the initial index and length of each contiguous segment
2 2 1 1 1 2 will be stored as
Length 3 2 1
Index  2 0 5
Now remove the longest and leftmost contiguous segment (which will be the first value of set)
and if previous and next segment have same value we have to merge them
*/
#include <bits/stdc++.h>
using namespace std;
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, i;
	cin >> n;
	int a[n];

	int initial_values[n];
	int move_forward[n];
	int move_backward[n];

	set<pair<int,int>>s;

	for(i = 0; i < n; ++i){
		cin >> a[i];
	}
	
	int previ = -1;

	for(i = 0; i < n; ){
		int val = a[i];
		int initi = i;
		int ct = 0;
		while(i < n && a[i] == val){
			ct++;
			move_backward[i] = initi;
			i++;
		}
		move_forward[initi] = i;
		move_backward[initi] = previ;
		previ = initi;
		s.insert({-ct, initi});
		initial_values[initi] = ct;
	}

	int ans = 0;

	while(s.size() > 0){
		ans++;
		pair<int,int>p = *s.begin();
		s.erase(s.begin());	

		if(p.second - 1 < 0)continue;

		int pehla = move_backward[p.second], doosra = move_forward[p.second];

		if(pehla >= 0)move_forward[pehla] = doosra;
		if(doosra < n)move_backward[doosra] = pehla;

		if(pehla < 0 || doosra >= n)continue;

		if(a[pehla] == a[doosra]){
			auto it1 = s.find({-initial_values[pehla], pehla});
			if(it1 == s.end())continue;
			auto it2 = s.find({-initial_values[doosra], doosra});
			if(it2 == s.end())continue;

			move_forward[pehla] = move_forward[doosra];
			if(move_forward[pehla] < n)
				move_backward[move_forward[pehla]] = pehla;

			s.erase(it1);
			s.erase(it2);
			s.insert({-(initial_values[pehla] + initial_values[doosra]), pehla});
			initial_values[pehla] = initial_values[pehla] + initial_values[doosra];
		}
	}

	cout << ans << endl;

	return 0;
}
