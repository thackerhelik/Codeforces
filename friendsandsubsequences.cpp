/*
Fix l and search for rmin and rmax
so nlogn
add rmax - rmin + 1 every iteration if it is possible to start an interval from l
*/
#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(i = 0; i < n; ++i)
#define ll long long int

const int MAXN = 200005;
const int LOGMAXN = 20;

int n;
int a[MAXN], b[MAXN];

int MA[MAXN][LOGMAXN];
int MB[MAXN][LOGMAXN];



void Apreprocess(){
	int i, j;
	
    for(i = 0; i < n; ++i)
		MA[i][0] = i;

	for(j = 1; (1<<j) <= n; ++j){
		for(i = 0; i+(1<<j)-1 < n; ++i){
			if(a[MA[i][j-1]] >= a[MA[i+(1<<(j-1))][j-1]]){
				MA[i][j] = MA[i][j-1];
			}
			else{
				MA[i][j] = MA[i+(1<<(j-1))][j-1];
			}
		}
	}
}


void Bpreprocess(){
	int i, j;
	
    for(i = 0; i < n; ++i)
		MB[i][0] = i;
	
    for(j = 1; (1<<j) <= n; ++j){
		for(i = 0; i+(1<<j)-1 < n; ++i){
			if(b[MB[i][j-1]] <= b[MB[i+(1<<(j-1))][j-1]]){
				MB[i][j] = MB[i][j-1];
			}
			else{
				MB[i][j] = MB[i+(1<<(j-1))][j-1];
			}
		}
	}
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    int i;
    cin >> n;
    fo(i, n)cin >> a[i];
    fo(i, n)cin >> b[i];  

    Apreprocess();
    Bpreprocess();

    ll ans = 0;


    for(i = 0; i < n; ++i){
        int lo = i, hi = n - 1;
        int rmaxqa, rminqb, mid;
        int res1 = -1;
        int res2 = -1;

        while(lo <= hi){
            mid = (lo + hi) >> 1;
            int k = log2(mid - i + 1);

            if(a[MA[i][k]] >= a[MA[mid - (1<<k) + 1][k]])rmaxqa = MA[i][k];
            else rmaxqa = MA[mid - (1<<k) + 1][k];
            
            if(b[MB[i][k]] <= b[MB[mid - (1<<k) + 1][k]])rminqb = MB[i][k];
            else rminqb = MB[mid - (1<<k) + 1][k];
            
            if(a[rmaxqa] == b[rminqb]){
                res1 = mid;
                lo = mid + 1;
            }
            else if(a[rmaxqa] > b[rminqb]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }

        }

        lo = i, hi = n - 1;
        while(lo <= hi){
            mid = (lo + hi) >> 1;
            int k = log2(mid - i + 1);

            if(a[MA[i][k]] >= a[MA[mid - (1<<k) + 1][k]])rmaxqa = MA[i][k];
            else rmaxqa = MA[mid - (1<<k) + 1][k];
            
            if(b[MB[i][k]] <= b[MB[mid - (1<<k) + 1][k]])rminqb = MB[i][k];
            else rminqb = MB[mid - (1<<k) + 1][k];
            
            if(a[rmaxqa] == b[rminqb]){
                res2 = mid;
                hi = mid - 1;
            }
            else if(a[rmaxqa] > b[rminqb]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }

        }

        if(res1 == -1){
            assert(res2 == -1);
            continue;
        }
        

        ans = ans + (res1 - res2 + 1);

    }

    cout << ans << endl;
    return 0;
}

