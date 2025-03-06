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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    for (int i = 0; i < n; i++)  dp[i][0] = a[i][0];
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            ll best = dp[i][j - 1];

            if (i > 0) best = max(best, dp[i - 1][j - 1]);
            if (i < n - 1) best = max(best, dp[i + 1][j - 1]); 
            
            dp[i][j] = a[i][j] + best;
        }
    }
    ll res = LLONG_MIN;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i][m - 1]);

    cout << res << endl;
}
