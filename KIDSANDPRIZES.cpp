/*
Find the probabilty by formula
Box 1 not used by M students is ((N-1)/N) probabilty
same for all boxes so N*((N-1)/N)^M
answer would be N - N*((N-1)/N)^M since total N boxes are there
*/ 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("kids.in");
	ofstream cout("kids.out");
	long long int n, m;
	cin >> n >> m;
	long double val = 1.0;
	for(int i = 0; i < m; ++i){
		val = val * ((n-1)*1.0/n);
	}
	long double ans = n - n*1.0*val;
	cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
