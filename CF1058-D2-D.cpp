/*
2 * Area of a triangle = |x1(y2-y3) - x2(y1-y3) + x3(y1-y2)|
If the coordinates are integers then 2*area has to be integer
So if 2*n*m/k is not an integer then answer is NO directly
Now we can fix one point to be (0,0)
so the formula is 2*Area = |x3y2-x2y3|
We can assume that x3y2 >= x2y3
so 2*area = x3y2 - x2y3
Now let 2*area = val
We find the lowest integer k such that n*k >= val and n*(k-1) < val
Now we can prove that n*k - val < n
So let y3 be 1 and x2 be n*k - val
*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    ll n, m, k;
   	cin >> n >> m >> k;

   	if((2LL*n*m) % k != 0){
   		cout << "NO" << endl;
   		return 0;
   	}        

   	ll val = (2LL*n*m)/k;

   	ll x1 = n;
   	ll y1;
   	if(val % n == 0)y1 = val / n;
   	else y1 = (val / n) + 1;

   	ll diff = x1*1LL*y1 - val;

   	ll y2 = 1;
   	ll x2 = diff;

   	cout << "YES" << endl;

   	cout << "0 0" << endl;

   	swap(y1, y2);

   	cout << x1 << " " << y1 << endl;
   	cout << x2 << " " << y2 << endl;

    return 0;
}
