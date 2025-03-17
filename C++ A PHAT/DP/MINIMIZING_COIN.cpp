#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int n, x;
    cin >> n >> x;
    vector<ll> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    vector<ll> dp(x + 1, LLONG_MAX);
    dp[0] = 0; 
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coin[j] && dp[i - coin[j]] != LLONG_MAX) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    if (dp[x] == LLONG_MAX) cout << -1 << endl;
    else cout << dp[x] << endl;
}
