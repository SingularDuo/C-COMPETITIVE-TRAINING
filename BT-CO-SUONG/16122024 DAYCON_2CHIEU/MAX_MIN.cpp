#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int a[1005][1005];
int f[1005][1005];
void init() {
    freopen("MAX_MIN.INP", "r", stdin);
    freopen("MAX_MIN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
    }
    ll stop = (n/2)+1;
    ll maxx = LLONG_MIN, minn = LLONG_MAX;
    for(int i = n; i >= stop; i--){
        ll curr = f[i][i]+f[n-i][n-i]-f[n-i][i]-f[i][n-i]-(f[i-1][i-1]+f[n-i+1][n-i+1]-f[n-i+1][i-1]-f[i-1][n-i+1]);
        maxx = max(maxx, curr);
        minn = min(minn, curr);
    }
    cout << maxx << endl;
    cout << minn << endl;
    return 0;
}
