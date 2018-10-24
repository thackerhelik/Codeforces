/*
first we change the character array by using dp
for a cell x,y we can either come from x-1,y or x,y-1 (if some not valid skip)
if k > 0 for any then we can replace the current x,y cell to a if it is not a and make k - 1

then when we have array we can do bfs from start to get the lexicographically smallest string
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

const int MAXN = 2005;

int dp[MAXN][MAXN];
char a[MAXN][MAXN];
bool usedcell[MAXN][MAXN];

//a cell denoted as row*i + col
vector<int>adj[MAXN*MAXN];

int n, k;

bool isvalid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int i, j;
    cin >> n >> k;

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    if(a[0][0] == 'a')dp[0][0] = k;
    else{
        if(k == 0)dp[0][0] = 0;
        else{
            a[0][0] = 'a';
            dp[0][0] = k - 1;
        }
    }

    for(j = 1; j < n; ++j){
        if(a[0][j] == 'a' || dp[0][j-1] <= 0){
            dp[0][j] = dp[0][j-1];
        }
        else{
            a[0][j] = 'a';
            dp[0][j] = dp[0][j-1] - 1;
        }
    }

    for(i = 1; i < n; ++i){
        if(a[i][0] == 'a' || dp[i-1][0] <= 0){
            dp[i][0] = dp[i-1][0];
        }
        else{
            a[i][0] = 'a';
            dp[i][0] = dp[i-1][0] - 1;
        }
    }

    for(i = 1; i < n; ++i){
        for(j = 1; j < n; ++j){
         
            if(a[i][j] == 'a'){
                if(dp[i][j - 1] == 0 && dp[i - 1][j] == 0){
                    if(a[i][j - 1] <= a[i-1][j]){
                        dp[i][j] = dp[i][j - 1];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else if(dp[i][j - 1] >= dp[i - 1][j]){
                    dp[i][j] = dp[i][j - 1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
            else{
                if(dp[i][j - 1] == 0 && dp[i - 1][j] == 0){
                    if(a[i][j - 1] <= a[i-1][j]){
                        dp[i][j] = dp[i][j - 1];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else if(dp[i][j - 1] >= dp[i - 1][j]){
                    dp[i][j] = dp[i][j - 1] - 1;
                    a[i][j] = 'a';
                }
                else{
                    dp[i][j] = dp[i-1][j] - 1;
                    a[i][j] = 'a';
                }
            }

        }
    }


    string ans =  "";

    i = 0;
    j = 0;

    ans.pb(a[0][0]);

    queue< pair< pair<int,int>, int > >q;
    q.push({{i, j}, 0});
    usedcell[0][0] = true;

    while(1){
        bool done = false;
        bool used[30] = {0};
        queue< pair< pair<int,int>, int > >tempq;
        int level = q.front().se;
        while(!q.empty() && q.front().se == level){
            int x = q.front().fi.fi;
            int y = q.front().fi.se;
            if(x == n - 1 && y == n - 1){done = true;break;}
            if(isvalid(x, y + 1)){
                used[a[x][y+1] - 'a'] = 1;
            }
            if(isvalid(x + 1, y)){
                used[a[x+1][y] - 'a'] = 1;
            }
            tempq.push(q.front());
            q.pop();
        }

        if(done)break;

        char firstused = '#';
        for(int te = 0; te < 26; ++te){
            if(used[te]){
                firstused = char(te + 'a');
                break;
            }
        }

        ans.pb(firstused);

        while(!tempq.empty()){
            int x = tempq.front().fi.fi;
            int y = tempq.front().fi.se;
            int newlevel = tempq.front().se + 1;
            if(!usedcell[x][y+1] && isvalid(x, y + 1) && a[x][y+1] == firstused){
                q.push({{x, y + 1}, newlevel});
                usedcell[x][y + 1] = true;
            }
            if(!usedcell[x+1][y] && isvalid(x + 1, y) && a[x+1][y] == firstused){
                q.push({{x + 1, y}, newlevel});
                usedcell[x+1][y] = true;
            }
            tempq.pop();
        }

    }

    cout << ans << endl;

return 0;
}
