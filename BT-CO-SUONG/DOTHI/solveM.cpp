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
 * Generated on: 2025-07-02 08:39:06
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

__TOISETHIVOI__ {
    fast;
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> color(n + 1, -1);
    bool is_bipartite = true;

    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(auto v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if(color[v] == color[u]) {
                        is_bipartite = false;
                        break;
                    }
                }
                if(!is_bipartite) break;
            }
        }
        if(!is_bipartite) break;
    }

    cout << (is_bipartite ? "YES" : "NO") << endl;
    return 0;
}
