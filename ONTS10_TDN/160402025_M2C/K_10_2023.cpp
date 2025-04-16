#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
const int MOD = 1e9;
KING_PHAT
{
    fast;
    int m,n,k,q;
    cin>>m>>n>>k>>q;
    vector<vector<ll>> a(m+1, vector<ll>(n+1, 0));
    while(k--)
    {
        int kx,ky;
        cin>>kx>>ky;
        a[kx][ky] = 1;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        vector<vector<ll>> dp(m+1, vector<ll>(n+1,0));
        dp[x-1]
    }

}