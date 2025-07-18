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
 * Generated on: 2025-06-25 14:36:48
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
  freopen("GRAPH_A6.inp", "r", stdin);
  freopen("GRAPH_A6.out", "w", stdout);
  fast;
}
__TOISETHIVOI__ {

    init();
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x) {
            adj[i].push_back(x);
            if (cin.peek() == '\n') break;
        }
    }

    set<pair<int, int>> edges;
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (u < v) {
                edges.insert({u, v});
            }
        }
    }

    for (auto& i : edges) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
