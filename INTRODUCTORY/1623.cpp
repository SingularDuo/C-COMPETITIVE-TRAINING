// Problem: Apple Division
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1623
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int n, sum = 0, res = LLONG_MAX;
vector<int> a;

void gen(int idx, int currsum) {
    if (idx == n) {
        int group = sum - currsum;
        res = min(res, abs(currsum - group));
        return;
    }
    gen(idx + 1, currsum + a[idx]); 
    gen(idx + 1, currsum);          
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    gen(0, 0);
    cout << res << "\n";
}
