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
    int n;
    cin>>n;
    vector<vector<ll>> a(n+1,vector<ll>(n+1,0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)cin>>a[i][j];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    dp[1][1] = a[1][1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j == 1)continue;
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + a[i][j];
        }
    }
    cout<<dp[n][n];
}