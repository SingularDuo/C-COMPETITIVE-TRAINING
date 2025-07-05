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
 * Generated on: 2025-07-02 09:20:57
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int INF = 2e18;
const int LIMIT = 1e6;

vector<vector<int>> adj;
set<pair<int, int>> visited;
int ans = 0;

const int MAX_DEPTH = 1e5;
int depth = 0;

void dfs(int u) {
    if (ans >= LIMIT || depth >= MAX_DEPTH) return;
    ans++;
    depth++;
    for (int v : adj[u]) {
        int a = min(u, v), b = max(u, v);
        if (visited.count({a, b})) continue;
        visited.insert({a, b});
        dfs(v);
        visited.erase({a, b});
    }
    depth--;
}

__TOISETHIVOI__ {
    freopen("PATH.inp", "r", stdin);
    freopen("PATH.out", "w", stdout);
    fast;
    int n, m;
    cin >> n >> m;
    if (n <= 0 || n > 1000 || m < 0 || m > n * (n - 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    adj.resize(n + 1);
    ans = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 1 && u <= n && v >= 1 && v <= n && u != v) {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    dfs(1);
    cout << min(ans, LIMIT) << endl;

    return 0;
}
