#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll>(m));
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            if(i == 0 || j == 0 ||  i == n-1 || j == m-1)sum+= a[i][j];
        }
    }
    cout<<sum;
}