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
 * Generated on: 2025-07-02 10:34:01
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

const int N = 1e5 + 5;

vector<int> adj[N], root;
bool visited[N];

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

__TOISETHIVOI__ {
    freopen("BUILDROAD.inp", "r", stdin);
    freopen("BUILDROAD.out", "w", stdout);
    fast;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            root.pb(i);
            dfs(i);
        }
    }

    cout << root.si - 1 << endl;
    for (int i = 1; i < root.si; i++) {
        cout << root[i - 1] << " " << root[i] << endl;
    }

    return 0;
}
