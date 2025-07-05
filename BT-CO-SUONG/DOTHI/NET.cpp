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
 * Generated on: 2025-05-30 23:03:47
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
  freopen("TPLT.inp", "r", stdin);
  freopen("TPLT.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> visited(n + 1, false);

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (auto& j : adj[u])
            {
                if (!visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        res++;
    }

    cout << res << endl;
    return 0;
}
