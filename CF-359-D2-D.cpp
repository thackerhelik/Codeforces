/*
gcd(l, r) == min(l, r)
we can find them in O(1) by sparse table (O(nlogn) preprocessing)
then binary search on length
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int LOGMAXN = 20;
int a[MAXN];
int M[MAXN][LOGMAXN];
int M2[MAXN][LOGMAXN];
bool flag;
vector<int>ans;

void preprocess(int n){
    int i, j;
    for(i=0;i<n;++i)M[i][0] = a[i]; //length 1 ka interval
    for(j=1;(1<<j)<=n;++j){ //length of interval (2^j)
        for(i=0;i+(1<<j)-1<n;++i){
            M[i][j] = __gcd(M[i][j-1], M[i+(1<<(j-1))][j-1]);
        }
    }
}

void preprocess2(int n){
    int i, j;
    for(i=0;i<n;++i)M2[i][0] = i;
    for(j=1;(1<<j)<=n;++j){
        for(i=0;i+(1<<j)-1<n;++i){
            if(a[M2[i][j-1]] <= a[M2[i+(1<<(j-1))][j-1]])
                M2[i][j] = M2[i][j-1];
            else
                M2[i][j] = M2[i+(1<<(j-1))][j-1];
        }
    }
}

bool check(int n, int x){
    int i, k, gcd, rmq;
    for(i = 0; i <= n - x; ++i){
        k = static_cast<int>(log2(x));
        gcd = __gcd(M[i][k], M[i+x-1 - (1<<k) + 1][k]);
        if(a[M2[i][k]] <= a[M2[i+x-1 - (1<<k) + 1][k]])
            rmq = M2[i][k];
        else
            rmq = M2[i+x-1 - (1<<k) + 1][k];
        if(gcd == a[rmq])
            ans.push_back(i);
    }
    return ((ans).size() > 0);
}

int main() {
    vector<int>final;
    int i, n;
    int res = 1;
    cin >> n;
    for(i=0;i<n;++i)cin >> a[i];
    preprocess(n);
    preprocess2(n);
    int lo = 1, hi = n;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        flag = false;
        ans.clear();
        if(check(n, mid)){
            final = ans;
            res = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << final.size() << " " << res - 1 << endl;
    for(auto it: final)
        cout << it + 1 << " ";
    cout << endl;
    return 0;
}
