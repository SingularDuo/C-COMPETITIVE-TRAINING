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
    int n, m;
    cin>>n>>m;
    vector<vector<ll>> a(n+1, vector<ll>(m+1));
    vector<vector<ll>> l(n+1, vector<ll>(m+1));
    vector<vector<ll>> c(n+1, vector<ll>(m+1));
    vector<vector<ll>> f(n+1, vector<ll>(m+1));
    ll res = LLONG_MIN;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == a[i][j-1])
            {
                l[i][j] = l[i][j-1]+1;
            }
            else l[i][j] = 1;
            if(a[i-1][j] == a[i][j])
            {
                c[i][j] = c[i-1][j] + 1;
                
            }
            else c[i][j] = 1;
            if(a[i][j] == a[i-1][j-1])
            {
                f[i][j] = min(min(l[i][j], c[i][j]), f[i-1][j-1]+1);
            }
            else f[i][j] = 1;
            res  = max(res, f[i][j]);
        }
    }
    cout<<res;

}