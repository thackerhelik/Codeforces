/*
it is easy to see that we can binary search for lengths >= 5k. After that we test our luck by
selecting a random integer in range l to r and then querying it. If does not work we know that we can increase the bound by
2k (k on each left and right) and then query and then again we can go to the random step.
The probability of failure if (49/50)^2200 (roughly since 4500 queries - 60 for first reduction and then every time we query
we have to query a range of 2k higher.
*/
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define ll long long int
using namespace std;

ll n, k;


string query(ll l, ll r){
    cout << l << " " << r << endl;
    fflush(stdout);
    string response;
    cin >> response;
    return response;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //srand(time(NULL));

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> n >> k;
    ll lo = 1, hi = n, ct = 4500;
    while(1){
        if((hi - lo) >= 5LL*k){
            ll mid = (lo + hi) >> 1;
            string s = query(lo, mid);
            if(s == "Bad"){
                return 0;
            }
            else if(s == "Yes"){
                lo = max(1LL, lo - k);
                hi = min(n, mid + k);
            }
            else{
                lo = max(1LL, mid + 1 - k);
                hi = min(n, hi + k);
            }
        }
        else{
            if(hi - lo + 1 <= 0)hi = lo;
            assert(hi - lo + 1 > 0);
            ll random = uniform_int_distribution<ll>(lo, hi)(rng);
            string s = query(random, random);
            if(s == "Yes"){
                return 0;
            }
            else if(s == "No"){
                lo = max(1LL, lo - k);
                hi = min(n, hi + k);
            }
            else{
                return 0;
            }
        }
    }
    return 0;
}
