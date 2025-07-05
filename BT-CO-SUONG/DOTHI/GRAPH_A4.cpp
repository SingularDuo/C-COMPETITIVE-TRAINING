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
 * Generated on: 2025-06-24 09:23:43
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
    freopen("GRAPH_A4.INP", "r", stdin);
    freopen("GRAPH_A4.OUT", "w", stdout);
    fast;
}

const int MAXN = 1005;

__TOISETHIVOI__ {
    init();

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1 && j > i) { 
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (int v : adj[i]) cout << " " << v;
        cout << endl;
    }

    return 0;
}
