/*
2 pointers approach to find sum
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;
typedef vector<int> vi;

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    #endif

    ll n, m;
    cin >> n;

    ll a[n + 5];

    ll i;

    fo(i, n)cin >> a[i];


    cin >> m;
    ll b[m + 5];

    fo(i, m)cin >> b[i];        

    ll ap = 0, bp = 0;


    ll ans = 0;

    while(ap < n && bp < m){
        if(a[ap] == b[bp]){
            ans++;
            ap++;
            bp++;
            continue;
        }
        ll s1 = 0, s2 = 0;
        while(ap < n && bp < m && ((s1 != s2) || (s1 == 0)) ){
            if(s1 == s2){
                s1 += a[ap];
                s2 += b[bp];
                ap++;
                bp++;
            }
            else if(s1 < s2){
                s1 += a[ap];
                ap++;
            }
            else{
                s2 += b[bp];
                bp++;
            }
        }

        while(ap < n && s1 != s2){
            s1 += a[ap];
            ap++;
        }
        while(bp < m && s1 != s2){
            s2 += b[bp];
            bp++;
        }

        if(s1 != s2){
            cout << -1 << endl;
            return 0;
        }

        // cout << s1 << " " << s2 << endl;
        // ap++;
        // bp++;
        ans++;
    }   



    if(ap < n || bp < m)cout << -1 << endl;
    else cout << ans << endl;

    //#if !ONLINE_JUDGE
    //    cout << fixed << setprecision(12) << "-------------------------------------------------\n";
    //    cout << double(clock())/CLOCKS_PER_SEC << " seconds" << endl;
    //#endif
    return 0;
}
