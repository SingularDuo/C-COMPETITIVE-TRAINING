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
 * Generated on: 2025-07-02 15:42:22
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
    freopen("EDGE.inp", "r", stdin);
    freopen("EDGE.out", "w", stdout);
    fast;
}

__TOISETHIVOI__ {
    init();
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) cin >> order[i];

    reverse(all(order));
    vector<bool> active(n + 1, false);
    vector<int> vis_time(n + 1, 0);
    int timer = 1;
    vector<string> res;

    for (int i = 0; i < n; i++) {
        int u = order[i];
        active[u] = true;
        queue<int> q;
        q.push(u);
        vis_time[u] = timer;
        int count = 1;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int v : adj[cur]) {
                if (active[v] && vis_time[v] != timer) {
                    vis_time[v] = timer;
                    q.push(v);
                    count++;
                }
            }
        }

        int alive = i + 1;
        res.pb(count == alive ? "YES" : "NO");
        timer++;
    }

    reverse(all(res));
    for (auto &s : res) cout << s << endl;

    return 0;
}
