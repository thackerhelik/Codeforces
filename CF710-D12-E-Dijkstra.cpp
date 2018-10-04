/*
Such problems can be modelled as a graph and finding shortest path from given config to dest config
from a node of x a's we can go to x-1 and x+1 if odd
if x we can go to x-1 x+1 and x/2
find the shortest path using dijkstra
note that some optimizations are needed in this
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 100000000000000000

ll n;
ll x, y;
vector<ll>d;

ll mn = 0;

void dijkstra(ll s){
	d.assign(n+4, INF);
	d[s] = 0;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>q;
	q.push({0, s});
	while(!q.empty()){
		int v = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if(d_v != d[v])
			continue;
		ll to, len;
		to = v + 1;
		len = x;
		if(d[v] + len <= mn){
			if(to < (n+3) && (d[v] + len < d[to])){
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
		to = v - 1;
		len = x;
		if(d[v] + len <= mn){
			if(v != 0 && (d[v] + len < d[to])){
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
		if(v % 2 != 0)continue;
		to = v/2;
		len = y;
		if(d[v] + len <= mn){
			if(v != 0 && (d[v] + len < d[to])){
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> x >> y;	
	mn = n*x;
	dijkstra(n);
	cout << d[0] << endl;
	return 0;
}
