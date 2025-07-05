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
#define endl "\n"
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define __TOISETHIVOI__ signed main()


__TOISETHIVOI__ {
    freopen("MAXDINHLT.INP", "r", stdin);
    freopen("MAXDINGLT.OUT", "w", stdout);
    fast;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<bool> vis(n + 1, false);
    vector<int> best;

    function<void(int, vector<int>&)> dfs = [&](int u, vector<int>& comp) {
        vis[u] = true;
        comp.pb(u);
        for (int v : g[u]) {
            if (!vis[v]) dfs(v, comp);
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, comp);
            sort(all(comp));
            if (comp.size() > best.size() ||
               (comp.size() == best.size() && comp < best)) {
                best = comp;
            }
        }
    }

    cout << best.size() << endl;
    for (int x : best) cout << x << " ";
    return 0;
}
