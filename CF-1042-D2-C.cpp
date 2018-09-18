/*
If we have a zero and odd number of -ve numbers we can consume one of the negative numbers to make the product >= 0
basically having a 0 makes the question tricky
*/

/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;


ll a[200005];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


    ll i, n, o, p, z;
    o = p = z = 0;
    cin >> n;


    for(i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] == 0)z++;
        else if(a[i] > 0)p++;
        else o++;
    }

    if(z && o%2 == 1){

        vector<ll>zero;
        vector<ll>nonzero;

        ll pos = -1;
        ll mx = -100000000000000;
        for(i = 0; i < n; ++i){
            if(a[i] < 0 && a[i] > mx){
                mx = a[i];
                pos = i;
            }
        }
        for(i = 0; i < n; ++i){
            if(i == pos || a[i] == 0)zero.pb(i);
            else nonzero.pb(i);
        }

        for(i = 0; i < sz(zero) - 1; ++i){
            cout << 1 << " " << zero[i] + 1 << " " << zero[i+1] + 1 << endl;
        }
        if(sz(nonzero) == 0){
            return 0;
        }
        if(sz(zero) > 0)cout << 2 << " " << zero[sz(zero) - 1] + 1 << endl;
        for(i = 0; i < sz(nonzero) - 1; ++i){
            cout << 1 << " " << nonzero[i] + 1 << " " << nonzero[i+1] + 1 << endl;
        }

        return 0;
    }

    if(o % 2 == 0){

            vector<ll>zero;
            vector<ll>nonzero;

            for(i = 0; i < n; ++i){
                if(a[i] == 0){
                    zero.pb(i);
                }
                else{
                    nonzero.pb(i);
                }
            }
            for(i = 0; i < sz(zero) - 1; ++i){
                cout << 1 << " " << zero[i] + 1 << " " << zero[i+1] + 1 << endl;
            }
            if(sz(nonzero) == 0){
                return 0;
            }
            if(sz(zero) > 0)cout << 2 << " " << zero[sz(zero) - 1] + 1 << endl;
            for(i = 0; i < sz(nonzero) - 1; ++i){
                cout << 1 << " " << nonzero[i] + 1 << " " << nonzero[i+1] + 1 << endl;
            }

    }
    else{
        ll pos = -1;
        ll mx = -100000000000000;
        for(i = 0; i < n; ++i){
            if(a[i] < 0 && a[i] > mx){
                mx = a[i];
                pos = i;
            }
        }

        vector<ll>nonzero;
        for(i = 0; i < n; ++i){
            if(i == pos)continue;
            nonzero.pb(i);
        }
        cout << 2 << " " << pos + 1 << endl;
        for(i = 0; i < sz(nonzero) - 1; ++i){
            cout << 1 << " " << nonzero[i] + 1 << " " << nonzero[i+1] + 1 << endl;
        }
    }

    return 0;
}
