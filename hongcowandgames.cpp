/*
this is a very nice solution
so basically for n = 8
query 1,3,5,7 and then 2,4,6,8
now from 1,3,5,7 you can get minimum in 2,4,6,8 and vice versa so update
do this for all the 10 bits and seperate all 0 values and 1 values
*/
#include <bits/stdc++.h>
using namespace std;
void ask(vector<int>&query){
	cout << (query).size() << endl;
	for(auto it: query)
		cout << it << " ";
	cout << endl;
	fflush(stdout);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    int n, d;
    cin >> n;
    int mn[n + 5];
    for(int i = 0; i < n + 5; ++i)mn[i] = 2e9 + 1;
    for(int bit = 0; bit < 10; ++bit){
    	for(int val = 0; val <= 1; ++val){
    		vector<int>query;
    		for(int i = 1; i <= n; ++i){
    			if(((i>>bit)&1) == val)query.push_back(i);
    		}
    		if((query).size() != n && (query).size() != 0){
    			ask(query);
    			for(int i = 1; i <= n; ++i){
    				cin >> d;
    				if(((i>>bit)&1) == (1 - val))mn[i] = min(mn[i], d);
    			}
    		}
    	}
    }

    cout << -1 << endl;
    for(int i = 1; i <= n; ++i){
    	cout << mn[i] << " ";
    }
    cout << endl;
    fflush(stdout);

    return 0;
}
