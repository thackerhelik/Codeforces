#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)

typedef long long int ll;



int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    int n;
    cin >> n;
    ll i, j;
    int a[n];
    int z = 0;

	unordered_map<int,int>m;

    fo(i, n){cin >> a[i]; m[a[i]]++; if(a[i] == 0)z++;}       

    int nxt = 0;

    int ass = 0, bss = 0;

    int ans = 0;

    unordered_set<int>s;

    for(i = 0; i < n; ++i){
    	
    	m[a[i]]--;
    	
    	for(j = 0; j < n; ++j){

    		if(i == j)continue;

    		if(a[i] == 0 && a[j] == 0){
    			ans = max(ans, z);
    			continue;
    		}

    		int cur = 2;

    		ass = a[i];
    		bss = a[j];


    		m[a[j]]--;


    		while(1){
    			nxt = ass + bss;
    			if(nxt > 1000000000 || nxt < -1000000000)break;
    			if(!m.count(nxt))break;
    			if(s.count(nxt)){
    				if(m[nxt] <= 1)break;
    			}
    			else{
    				if(m[nxt] <= 0)break;
    			}
    			s.insert(nxt);
				ass = bss;
				bss = nxt;
				cur++;	
		    	ans = max(ans, cur);
			}

			s.clear();


    		ans = max(ans, cur);

    		m[a[j]]++;
    	
    	}

    	m[a[i]]++;

    }

    cout << ans << endl;
    return 0;
}
