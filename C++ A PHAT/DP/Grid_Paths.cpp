#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int MOD = 1e9 + 7;

KING_PHAT
{
    fast;
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<ll>> dp(n, vector<ll>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char s;
            cin >> s;
            a[i][j] = (s == '.' ? 1 : 0);
        }
    }
    if (a[0][0] == 0) { 
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[0][i] = (a[0][i] ? dp[0][i - 1] : 0);
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = (a[i][0] ? dp[i - 1][0] : 0);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if (a[i][j]) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            } else {
                dp[i][j] = 0; 
            }
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}
