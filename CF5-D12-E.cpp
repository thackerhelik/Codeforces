/*
Let us first convert the problem from a circular one to a straight line.
So first find the maximum value in the array. (if multiple anyone)
and rotate the array around that point. Add the max value to the end so that it becomes circular.
Now consider any hill i.
We find 3 values l[i], r[i] and c[i]
l[i] -> index of the first hill to the left  of i such that height[l[i]] > height[i]
r[i] -> index of the first hill to the right of i such that height[r[i]] > height[i]
c[i] -> number of hills x between i and r[i] such that height[i] == height[x]

now for every node we add c[i] to answer
then we add (l[i], x) and (x, r[i]) only care to be taken is l[i] = 0 and r[i] = n which means
they are same element so we subtract 1 from answer
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll N = 1000000;
ll c[N + 5] = {0}, r[N + 5], l[N + 5], height[N + 5], ar[N + 5];

int main(){

	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	ll n;

	cin >> n;

	ll mx = 0, i, pos = 0;
	
	for(i = 0; i < n; ++i)
		cin >> ar[i];
	for(i = 0; i < n; ++i){
		if(ar[i] > mx){
			pos = i;
			mx = ar[i];
		}
	}	

	ll ct = 0;
	for(i = pos; i < n; ++i)
		height[ct++] = ar[i];
	for(i = 0; i < n; ++i)
		height[ct++] = ar[i];
	height[ct++] = mx;

	c[n] = 0;

	for(i = n - 1; i >= 0; --i){
		r[i] = i + 1;
		while(r[i] < n && height[i] > height[r[i]]){
			r[i] = r[r[i]];
		}		
		if(r[i] < n && height[i] == height[r[i]]){
			c[i] = c[r[i]] + 1;
			r[i] = r[r[i]];
		}
	}

	for(i = 1; i < n; ++i){
		l[i] = i - 1;
		while(l[i] > 0 && height[i] > height[l[i]]){
			l[i] = l[l[i]];
		}
		if(l[i] > 0 && height[i] == height[l[i]]){
			l[i] = l[l[i]];
		}
	}

	ll ans = 0;

	for(i = 0; i < n; ++i){
		ans = ans + c[i];
		if(height[i] == height[0])continue;
		ans = ans + 2;
		if(l[i] == 0 && r[i] == n)
			ans--;
	}

	cout << ans << endl;

	return 0;
}
