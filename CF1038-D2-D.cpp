/*
Basically we have to take difference of max and min and rest all can be any sign
Not sure about the proof although some intuition
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, a[500005];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    cin >> n;        

    ll i, j, k;

    for(i = 0; i < n; ++i)cin >> a[i];

    if(n == 1){
        cout << a[0] << endl;
        return 0;    
    }

    sort(a, a + n);

    ll ans = 0;

    ans = ans - a[0] + a[n-1];
    for(i = 1; i < n - 1; ++i){
        if(a[i] > 0)ans = ans + a[i];
        else ans = ans - a[i];
    }

    cout << ans << endl;

    return 0;
}
