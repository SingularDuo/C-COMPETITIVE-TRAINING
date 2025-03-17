#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    int n;
    cin>>n;
    vector<ll> dp(n+1, 1e9);
    // dp i la so buoc nho nhat de bien i ve 0
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = i;
        while(x > 0)
        {
            int d = x % 10;
            if(d > 0) dp[i] = min(dp[i], dp[i-d]+1);
            x/=10;
        }
    }
    cout<<dp[n];
    
}