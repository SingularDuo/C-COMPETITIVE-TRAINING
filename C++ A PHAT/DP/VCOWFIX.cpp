#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
signed main()
{
    int n, c;
    cin>>c>>n;
    bool ap = false;
    vector<ll> w(n+1);
    for(int i = 1; i <= n; i++){
        cin>>w[i];
        if(w[i] == c)ap = true;
    }
    if(ap)
    {
        cout<<c;
        return 0;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(c+1));
    for(int i  = 0; i <= c; i++)dp[0][i] = 0;
    for(int i = 0; i <= n; i++)dp[i][0] = 0;

    for(int i =1; i <= n; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            if(i - 1 >= 1)dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0)dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+w[i]);
        }
    }
    cout<<dp[n][c];
}
