/*
use a stack to find for all i l[i] such that it is the value at which the element is less than element at i
and similar for r[i]
then since ans1 >= ans2 >= ... >= ansn
traverse from end and update if the value is smaller than the next
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int a[MAXN], l[MAXN], r[MAXN], ans[MAXN];

stack<int>s;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)cin >> a[i];

    for (int i = 0; i < MAXN; ++i) {
        l[i] = -1;
        r[i] = n;
    }

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[s.top()] >= a[i])s.pop();
        if (!s.empty())l[i] = s.top();
        s.push(i);
    }

    while(!s.empty())s.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && a[s.top()] >= a[i])s.pop();
        if (!s.empty())r[i] = s.top();
        s.push(i);
    }

    for (int i = 0; i < n; ++i) {
        int len = r[i] - l[i] - 1;
        //cout << i << " " << l[i] << " " << r[i] << " -- " << len << endl;
        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 1; i <= n; ++i)cout << ans[i] << " ";
    cout << endl;


    return 0;
}
