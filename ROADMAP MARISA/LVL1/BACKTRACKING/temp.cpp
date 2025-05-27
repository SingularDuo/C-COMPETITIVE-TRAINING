#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long


signed main()
{
    ll n, m, q;cin>>n>>m>>q;
    vector<pair<ll, ll>> query(q);

    for(int i = 0; i <q; i++) cin>>query[i].first>>query[i].second;

    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i =  0; i < n; i++)
    {
        for(int j = 0; j < m; j++)cin>>a[i][j];
    }
}