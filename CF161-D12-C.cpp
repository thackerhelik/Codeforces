/*
for each depth k we have these cases
if l1 <= mid l2 <= mid r1 >= mid r2 >= mid we can include the middle character so answer can be min(r1, r2) - max(l1, l2) + 1
and then we cut the string into 2 parts 1 mid - 1 and mid + 1 to n, but notice they are same
so we can map the other string onto first one and query
some cases are trivial so instead of recurring, we just return the answer
Proof: Not that clear (someone explained on CF tutorial page)
for every query on (1, 2^depth - 1) we get 4 queries on (1, 2^(depth-1) - 1) and it follows proof similar to segment tree proof
we get O(k) as complexity.
Note to self: see after some days if the proof is clear after some days
*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int solve(int l1, int r1, int l2, int r2, int k){

	if(k == 0) return 1;
	
	int mid = (1 << (k-1));


	if(l1 > mid){
		l1 = l1 - mid;
		r1 = r1 - mid;
	}
	if(l2 > mid){
		l2 = l2 - mid;
		r2 = r2 - mid;
	}


	if(l1 <= l2 && r2 <= r1)return r2 - l2 + 1;
	if(l2 <= l1 && r1 <= r2)return r1 - l1 + 1;
	if(r1 < mid && r2 < mid)return solve(l1, r1, l2, r2, k - 1);
	if(r2 < mid)return max(solve(l1, mid - 1, l2, r2, k - 1), solve(1, r1 - mid, l2, r2, k - 1));
	if(r1 < mid)return max(solve(l1, r1, l2, mid - 1, k - 1), solve(l1, r1, 1, r2 - mid, k - 1));
	
	int res = min(r1, r2) - max(l1, l2) + 1;
	res = max(res, solve(l1, mid - 1, 1, r2-mid, k - 1));
	res = max(res, solve(l2, mid - 1, 1, r1-mid, k - 1));

	return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int ans = solve(l1, r1, l2, r2, 31);

    cout << ans << endl;

    return 0;
}
