#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main() {
    fast;
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> f(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    k--;
    ll res = LLONG_MIN;
    for (int i = 1; i + k <= n; i++) {
        for (int j = 1; j + k <= n; j++) {
            int nx = i + k;
            int ny = j + k;
            ll val = f[nx][ny] - f[i - 1][ny] - f[nx][j - 1] + f[i - 1][j - 1];
            res = max(res, val);
        }
    }

    cout << res << '\n';
    return 0;
}
