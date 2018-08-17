/* 
	just a map or a frequency array
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	
	map<int,int>m;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int>ans;
	
	int u = 0;
	
	for(int i = 0; i < n; ++i){
		
		if(a[i] > 0){
			m[a[i]]++;
		}
		else if(a[i] == 0){
			u++;
		}
		else{
			a[i] = -a[i];
			if(m.count(a[i]) > 0 && m[a[i]] > 0){
				m[a[i]]--;
			}
			else{
				if(u <= 0){
					cout << "No" << endl;
					return 0;
				}
				u--;
				ans.push_back(a[i]);
			}
		}
	}
	
	while(u--){
		ans.push_back(1);
	}
	
	cout << "Yes" << endl;
	for(auto it: ans){
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
