#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void init()
{
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
signed main() {
    init();
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(n, LLONG_MAX); 
    dp[0] = 0; 

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }

    cout << dp[n - 1] << endl; 
}
