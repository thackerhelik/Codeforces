/*
Initially we say that the array elements are at max value 1e9 and we maintain a diff array with all 0 initially
now we have go through the operations. If it is type 1 we have to change the array elements. So we change diff array.
for second type operation we have to set the array to the max possible value possible which is min(a[j], query[i] - diff[j])

now we loop the queries again, setting diff array if type 1 as above.
if it is type 2 we have to check if any (a[i] + diff[i]) is exactly equal to max.
*/
#include <bits/stdc++.h>
using namespace std;
int a[5005], d[5005], dd[5005], t[5005], l[5005], r[5005], n, m;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        a[i] = static_cast<int>(1e9);
    }
    for(int i = 0; i < m; ++i){
        cin >> t[i] >> l[i] >> r[i] >> dd[i];
        l[i]--; r[i]--;
        if(t[i] == 1){
            for(int j = l[i]; j <= r[i]; ++j){
                d[j] = d[j] + dd[i];
            }
        }
        else{
            for(int j = l[i]; j <= r[i]; ++j){
                a[j] = min(a[j], dd[i] - d[j]);
            }
        }
    }

    memset(d, 0, sizeof(d));

    for(int i = 0; i < m; ++i){
        if(t[i] == 1){
            for(int j = l[i]; j <= r[i]; ++j){
                d[j] = d[j] + dd[i];
            }
        }
        else{
            int x = static_cast<int>(-1e9);
            for(int j = l[i]; j <= r[i]; ++j){
                x = max(x, a[j] + d[j]);
            }
            if(x != dd[i]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
