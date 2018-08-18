/*
go from 1,1 to some point x1,y1 prioritizing down 
go from n,n to some point x2,y2 prioritizing left
(x1,y1) == (x2,y2)
*/
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define pb push_back

bool ask(int a, int b, int c, int d){
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	fflush(stdout);
	string response;
	cin >> response;
	if(response == "BAD"){
		exit(0);
	}
	else if(response == "YES")return true;
	else return false;
}

int main(){
    int n;
    cin >> n;

    int x = 1, y = 1; //starting point

    string ans1 = "", ans2 = "";

    //priority down
    for(int i = 0; i < n - 1; ++i){
    	if(ask(x + 1, y, n , n)){
    		x++;
    		ans1.pb('D');
    	}
    	else{
    		y++;
    		ans1.pb('R');
    	}
    }

    //priority left
    x = n, y = n;
    for(int i = 0; i < n - 1; ++i){
    	if(ask(1, 1, x, y - 1)){
    		y--;
    		ans2.pb('R');
    	}
    	else{
    		x--;
    		ans2.pb('D');
    	}
    }

    reverse(all(ans2));
    string finalans = ans1 + ans2;
    cout << "! " << finalans << endl;
    fflush(stdout);
    return 0;
}
