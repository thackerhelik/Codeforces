/*input
Brute force to pass using pragma
intended solution still not clear
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <stdio.h>
using namespace std;

unsigned char a[200000];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; ++i)
		scanf("%hhu", &a[i]);          

	int q;
	scanf("%d", &q);

	while(q--){
		int l, r;
		unsigned char x, y;
		scanf("%d%d%hhu%hhu", &l, &r, &x, &y);
		for(int i = l - 1; i < r; i++)
			if(a[i] == x)
				a[i] = y;
	}

	for(int i = 0; i < n; ++i){
		printf("%hhu ", a[i]);
	}
    return 0;
}
