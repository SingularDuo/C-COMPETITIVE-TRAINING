#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MOD = 1e9+7;
signed main()
{
    int n, x;
    cin>>n>>x;
    vector<ll> coin(n);
    for(int i = 0; i < n; i++)cin>>coin[i];
    vector<ll> dp(x+1,0);
    dp[0] = 1;
    for(auto i : coin)
    {
        for(int j = i; j <= x; j++)
        {
            dp[j] = (dp[j] + dp[j - i])%MOD;
        }
    }
    cout<<dp[x];
}