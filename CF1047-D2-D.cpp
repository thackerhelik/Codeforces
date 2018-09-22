/*
Probably missed a few cases in contest time.
Can also be solved using matching. But can be broken into cases.
1X6 2X4 2X5 3X4 can be completely filled with chessmen.
When n*m is odd we can not completely fill. There will be at least one empty cell left.
Editorial has alternate method also --> bipartite matching.
*/


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	

    ll n, m;
    ll ans = 0;

    cin >> n >> m;

    if(n > m)swap(n, m);

    if(n == 1){
        ll mm = m % 6;
        if(mm == 1)ans = max(ans, n*m - 1);
        else if(mm == 2)ans = max(ans, n*m - 2);
        else if(mm == 3)ans = max(ans, n*m - 3);
        else if(mm == 4)ans = max(ans, n*m - 2);
        else if(mm == 5)ans = max(ans, n*m - 1);
        else if(mm == 0)ans = max(ans, n*m);
    }
    else if(n == 2){
        if(m == 2){ans = 0;}
        else if(m == 3){ans = 4;}
        else if(m == 7){ans = 12;}
        else ans = n*m;
    }
    else{
        ans = (n*m/2)*2;
    }
    cout << ans << endl;

    return 0;
}

