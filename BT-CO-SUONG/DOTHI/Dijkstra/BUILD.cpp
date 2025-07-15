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
 * Generated on: 2025-07-09 09:03:09
*/
#include <bits/stdc++.h>
using namespace std;

// ========== Type Aliases ==========
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>

// ========== Short Macros ==========
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define si size()
#define endl "\n"

// ========== Loop Macros ==========
#define FOR(i,n)        for (int i = 0; i < n; ++i)
#define REP(i,a,b)      for (int i = a; i <= b; ++i)
#define FORD(i,a,b)     for (int i = a; i >= b; --i)
#define FORDEC(i,a,b,c) for (int i = a; i >= b; i -= c)

// ========== Fast I/O ==========
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ========== Output Shortcuts ==========
#define yes cout << "YES\n"
#define no cout << "NO\n"

// ========== Custom Macros ==========
#define __TOISETHIVOI__ signed main()
#define vec(a,b,c,d) vector<a> b(c,d)
#define debug(x) cerr << #x << " = " << x << endl;

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

vector<vector<int>> hoan_vi;
vi a;
vi current;
vector<bool> used;
vector<vi> min_dist;

void gen() {
    if (sz(current) == sz(a)) {
        hoan_vi.pb(current);
        return;
    }
    FOR(i, sz(a)) {
        if (!used[i]) {
            used[i] = true;
            current.pb(a[i]);
            gen();
            current.pop_back();
            used[i] = false;
        }
    }
}

void dijkstra(int start, int idx, const vector<vii> &adj, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n + 1, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int du = top.first;
        int u = top.second;
        if (du > dist[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    REP(i, 1, n) {
        min_dist[idx][i] = dist[i];
    }
}

// ========== Main ==========
__TOISETHIVOI__ {
    freopen("BUILD.inp", "r", stdin);
    freopen("BUILD.out", "w", stdout);
    fast;

    int n, m, k;
    cin >> n >> m >> k;

    a.resize(k);
    FOR(i, k) cin >> a[i];

    used.assign(k, false);
    gen();

    vector<vii> adj(n + 1);
    FOR(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    min_dist.assign(k, vi(n + 1, INF));
    FOR(i, k) {
        dijkstra(a[i], i, adj, n);
    }

    int minn = INF;

    for (auto& perm : hoan_vi) {
    int total = 0;

        for (int i = 1; i < k; ++i) {
            int u_val = perm[i - 1];
            int v_val = perm[i];
            int idx_u = find(all(a), u_val) - a.begin();
            total += min_dist[idx_u][v_val];
        }

            int end_val = perm.back();
            int idx_end = find(all(a), end_val) - a.begin();
            int ve = INF;
            REP(hq, 1, n) {
                if (find(all(a), hq) != a.end()) continue;
                /*if(min_dist[idx_end][hq] < ve)
                {
                    cerr<<hq<<endl;
                }*/
                ve = min(ve, min_dist[idx_end][hq]);
            }

            total += ve;
            /*if(total < minn)
            {
                for(auto& j : perm)cerr<<j<<" ";
                cerr<<endl;
                cerr<<ve<<endl;

            }*/
            minn = min(minn, total);
    }


    cout << minn * 2 << endl;

    return 0;
}
