#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void init()
{
    freopen("QBSTR.inp", "r", stdin);
    freopen("QBSTR.out", "w", stdout);
    fast;
}

KING_PHAT
{
    fast;
    init();
    string s1, s2;
    cin >> s1 >> s2;
    
    ll n = s1.size(), m = s2.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;
}
