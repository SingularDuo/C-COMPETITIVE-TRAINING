/*
        _.-- ,.--.
      .'   .'     /
       @       |'..--------._
     /      \._/              '.
    /  .-.-                     \
   (  /    \                     \
   \      '.                  | #
    \       \   -.           /
     :\       |    )._____.'   \
      "       |   /  \  |  \    )
    Kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: Kduckp
 * Generated on: 2025-07-02 17:17:53
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("BVDAISY.inp", "r", stdin);
  freopen("BVDAISY.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    bool ap = false;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == false)
        {
            ap = true;
            cout<<i<<endl;
        }
    }
    if(!ap)cout<<0;
    return 0;
}
