/*
The editorial says 200^200 is also big so they take another log
why log is because log is increasing function on +ve numbers (f(x) = log(x) f'(x) = 1/x now for x > 0 we get slope +ve) so if logx >= logy then x >= y
But this passes
*/
#include <bits/stdc++.h>
#define ld long double
#define ll long long int
using namespace std;

int main(){
    ld x, y, z;
    cin >> x >> y >> z;

    ld ans[15] = {0.0};

    ans[1] = pow(y, z)*log(x);
    ans[2] = pow(z, y)*log(x); //c*(log(pow(a, b)));
    ans[3] = z*log(pow(x, y));
    ans[4] = y*log(pow(x, z));

    ans[5] = pow(x, z)*log(y);
    ans[6] = pow(z, x)*log(y);
    ans[7] = z*log(pow(y, x));
    ans[8] = x*log(pow(y, z));

    ans[9] = pow(x, y)*log(z);
    ans[10] = pow(y, x)*log(z);
    ans[11] = y*log(pow(z, x));
    ans[12] = x*log(pow(z, y));

    ld mx = ans[1];

    for(int i = 1; i <= 12; ++i)
        mx = max(mx, ans[i]);

    for(int i = 1; i <= 12; ++i){
        if(abs(mx - ans[i]) < 1e-9){
            if(i == 1){
                cout << "x^y^z" << endl;
            }
            else if(i == 2){
                cout << "x^z^y" << endl;
            }
            else if(i == 3){
                cout << "(x^y)^z" << endl;
            }
            else if(i == 4){
                cout << "(x^z)^y" << endl;
            }
            else if(i == 5){
                cout << "y^x^z" << endl;
            }
            else if(i == 6){
                cout << "y^z^x" << endl;
            }
            else if(i == 7){
                cout << "(y^x)^z" << endl;
            }
            else if(i == 8){
                cout << "(y^z)^x" << endl;
            }
            else if(i == 9){
                cout << "z^x^y" << endl;
            }
            else if(i == 10){
                cout << "z^y^x" << endl;
            }
            else if(i == 11){
                cout << "(z^x)^y" << endl;
            }
            else if(i == 12){
                cout << "(z^y)^x" << endl;
            }
            return 0;
        }
    }

    return 0;
}
