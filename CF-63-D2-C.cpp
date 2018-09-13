/*
try all 3 and 4 digit numbers and go through all the guesses
if only 1 number gives all the guesses correct that is the answer
else we have 2 cases ... no number satisfies --> data incorrect
                     ... more than 1 --> more data
*/


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
typedef long long int ll;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi=acos(-1);
const ll mod=1000000007;
const int N = 11;
int a[N], b[N], c[N];
int n;

bool check(int number){

	string s = to_string(number);
	
	if(sz(s) == 3)s = "0" + s;
	
	for(int i = 0; i < sz(s); ++i){
		for(int j = i + 1; j < sz(s); ++j){
			if(s[i] == s[j])return false;
		}
	}

	for(int i = 0; i < n; ++i){
		//a[i] b[i] c[i]
		//b[i] should be equal to same position
		
		int bull = 0, cow = 0, tot = 0;

		//cow should be total same - same pos ... tot - bull

		string t = to_string(a[i]);

		if(sz(t) == 3)t = "0" + t;

		for(int j = 0; j < 4; ++j){
			if(s[j] == t[j])bull++;
		}

		//count 0 1 2 ..... and see
		for(int j = 0; j < 10; ++j){
			int aa = 0, bb = 0;
			for(int k = 0; k < 4; ++k){
				if(s[k] == (j + '0'))aa++;
				if(t[k] == (j + '0'))bb++;
			}
			tot = tot + min(aa, bb);	
		}

		cow = tot - bull;

		if(tot != (b[i] + c[i]))return false;
		if(cow != c[i])return false;
		if(bull != b[i])return false; 

	}

	return true;

}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    cin >> n;
    for(int i = 0; i < n; ++i)cin >> a[i] >> b[i] >> c[i];

    int ans = 0;

	vector<int>final;

	 //last is 9999
    for(int i = 100; i < 10000; ++i){
    	if(check(i)){
    		final.pb(i);
    		ans++;
    	}
    }

    if(ans == 0){
    	cout << "Incorrect data" << endl;
    }
    else if(ans > 1){
    	cout << "Need more data" << endl;
    }
    else{
    	string x = to_string(final[0]);
    	if(sz(x) == 3)cout << 0;
    	cout << x << endl;
    }
    return 0;
}

