/*
let sum = a + b
we have to distribute it into 2 sets such that sumA <= a and sumB <= b
Greedily distribute. 
Todo for me: Prove the greedy
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

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    ll i, j, a, b, n, m;
    cin >> a >> b;


    vector<ll>f;
    vector<ll>s;

    ll sum = a + b;

    ll val = 1;

    while((val)*(val+1)/2 < sum)val++;

    if((val)*(val+1)/2 > sum)val--;

    for(i = val; i >= 1; --i){
        if(b >= a){
            s.pb(i);
            b = b - i;
        }
        else{
            f.pb(i);
            a = a - i;
        }
    }

    cout << sz(f) << endl;
    for(auto it: f)cout << it << " ";
    cout << endl;
    cout << sz(s) << endl;
    for(auto it: s)cout << it << " ";
    cout << endl;
    return 0;
}
