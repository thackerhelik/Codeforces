/*
first duplicate the string so that circular problem is solved
now calculate only left and only right
not traverse left and binary search on right to find answer
*/
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define ll long long int

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	
	ll n, a, b, T;
	cin >> n >> a >> b >> T;
	string s;
	cin >> s;
	s = s + s;
	ll init = n;

	ll left[n + 1] = {0};
	ll right[n + 1] = {0};

	ll ans = 1;
	if(s[n] == 'w')ans += b;

	if(ans > T){
		cout << 0 << endl;
		return 0;
	}

	ll mx = 1; //global max
	//find out left and right times and see
	for(ll i = n - 1; i > 0; --i){
		if(s[i] == 'w')ans += b;
		ans++;
		left[n - i] = ans;
		if((ans + (n - i)*a) <= T){
			mx = max(mx, n - i + 1);
		}
	}

	ans = 0;
	for(ll i = n + 1; i < 2*n; ++i){
		if(s[i] == 'w')ans += b;
		ans++;
		right[i - n] = ans;
		if((ans + b + 1 + (i - n)*a) <= T){
			mx = max(mx, i - n + 1);
		}
	}

	//we will have to binary search on prefix sums
	for(ll i = 1; i < n; ++i){ //i is the number of steps taken in the left direction and we will find the number of steps taken in right by bs
		//travelling time would be 2*min(left, right)*a + max(left, right)*a
		//lets first check if it is possible to move i units right
		//if it is we have to check only the right part right*a + 2*left*a
		//else we have to do left*a + 2*right*a
		ll time = 2*i*a + i*a;
		time = time + left[i] + right[i];

		if(time <= T){
			ll lo = i, hi = n - 1;
			ll res = i, mid;
			mx = max(mx, i + i + 1);
			while(lo <= hi){
				mid = (lo + hi) >> 1;
				ll timer = mid*a + 2*i*a + left[i] + right[mid];
				if(timer <= T){
					res = mid;
					mx = max(mx, i + mid + 1);
					lo = mid + 1;
				}
				else{
					hi = mid - 1;
				}
			}
		}
		else{
			ll lo = 0, hi = i - 1;
			ll res = -1, mid;
			while(lo <= hi){
				mid = (lo + hi) >> 1;
				ll timer = 2*mid*a + i*a + left[i] +right[mid];
				if(timer <= T){
					res = mid;
					mx = max(mx, i + mid + 1);
					lo = mid + 1;
				}
				else{
					hi = mid - 1;
				}
			}
		}
	}

	  cout << min(n, mx) << endl;
    return 0;
}

