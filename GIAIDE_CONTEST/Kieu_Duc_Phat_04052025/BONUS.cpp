#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define int long long
void init()
{
    freopen("BONUS.inp", "r", stdin);
    freopen("BONUS.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}
signed main() {
    init();
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    vector<vector<int>> f(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f[i][j] = a[i][j];
            if (i > 0) f[i][j] += f[i-1][j];
            if (j > 0) f[i][j] += f[i][j-1];
            if (i > 0 && j > 0) f[i][j] -= f[i-1][j-1];
        }
    }

    ll res = LLONG_MIN;
    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = 0; j + k - 1 < n; j++) {
            ll v = f[i+k-1][j+k-1];
            if (i > 0) v -= f[i-1][j+k-1];
            if (j > 0) v -= f[i+k-1][j-1];
            if (i > 0 && j > 0) v += f[i-1][j-1];
            res = max(res, v);
        }
    }

    cout << res << endl;
    return 0;
}
