/*input
Prime factorization in O(logn) using sieve and storing smallest prime.
Then maintain a frequency array for the divisors of the array elements. The answer is minimum of n - freq[prime divisor]
tricky case is when smallest array element is gcd initially.
*/


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

typedef long long int ll;


int n;
int a[300005];

#define MAXN 15000005

// stores smallest prime factor for every number 
int spf[MAXN]; 

int freq[MAXN];
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
set<int> getFactorization(int x) 
{ 
    set<int> ret; 
    while (x != 1) 
    { 
        ret.insert(spf[x]); 
        x/=spf[x];
    } 
    return ret; 
} 

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    #endif


    sieve();


    int i;
 
    cin >> n;
    int mn = n;


    fo(i, n){
        cin >> a[i];
        // g1 = __gcd(g1, a[i]);
        set<int>p = getFactorization(a[i]);
        for(auto it: p){
            freq[it]++;
        }
    }        

    sort(a, a + n);

    int g1 = a[0], g2;
    i = 0;
    while(a[i] == a[0])i++;
    int ct = i;
    g2 = a[i];
    for(; i < n; ++i){
        g1 = __gcd(g1, a[i]);
        g2 = __gcd(g2, a[i]);
    }

    if(g2 > g1){
        mn = min(mn, ct);
        // return 0;
    }


    for(i = 2; i <= 15000000; ++i){
        if(n > freq[i]){
            mn = min(mn, n - freq[i]);
        }
    }

    
    if(mn == n)mn = -1;
    cout << mn << endl;

    return 0;
}
