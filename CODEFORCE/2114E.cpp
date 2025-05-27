#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> P(n + 1);
    vector<int> depth(n + 1);
    vector<ll> threat(n + 1);
    ll currMin = 0, currMax = 0;

    function<void(int, int)> dfs = [&](int u, int p) {
        if (depth[u] % 2 == 0) {
            threat[u] = P[u] - currMin;
        } else {
            threat[u] = currMax - P[u];
        }
        ll oldMin = currMin, oldMax = currMax;
        currMin = min(currMin, P[u]);
        currMax = max(currMax, P[u]);

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            P[v] = (depth[v] % 2 == 0) ? P[u] + a[v] : P[u] - a[v];
            dfs(v, u);
        }

        currMin = oldMin;
        currMax = oldMax;
    };

    depth[1] = 0;
    P[1] = a[1];
    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << threat[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
