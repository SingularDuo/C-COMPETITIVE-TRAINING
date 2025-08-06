/*
        _.-- ,.--.
      .'   .'     /
       @       '..--------._
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
 * Generated on: 2025-07-22
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define __TOISETHIVOI__ signed main()

const int INF = 2e18;
const int N = 2e5 + 5;

struct road {
    int u, v, t, h;
};
struct addition {
    int v, t, h;
    addition(int _v = 0, int _t = 0, int _h = 0) : v(_v), t(_t), h(_h) {}
};

struct state {
    int dist, u, hsum;
    bool operator>(const state &o) const {
        return dist > o.dist;
    }
};

void djk(int n, int start, int end, vector<road>& a, int k, vector<ll>& d) {
    vector<vector<addition>> adj(n + 1);
    for (int i = 0; i < (int)a.size(); ++i) {
        road r = a[i];
        adj[r.u].emplace_back(r.v, r.t, r.h);
        adj[r.v].emplace_back(r.u, r.t, r.h);
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(k, INF));
    priority_queue<state, vector<state>, greater<state>> pq;

    dist[start][0] = 0;
    pq.push({0, start, 0});

    while (!pq.empty()) {
        state cur = pq.top(); pq.pop();
        int du = cur.dist;
        int u = cur.u;
        int hsum = cur.hsum;

        if (du > dist[u][hsum]) continue;

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            addition e = adj[u][i];
            int v = e.v;
            int t = e.t;
            int h = e.h;
            int new_h = hsum + h;
            if (new_h >= k) continue;

            if (dist[v][new_h] > du + t) {
                dist[v][new_h] = du + t;
                pq.push({dist[v][new_h], v, new_h});
            }
        }
    }

    ll res = *min_element(all(dist[end]));
    cout << (res == INF ? -1 : res) << '\n';
}

__TOISETHIVOI__ {
    fast;
    freopen("HANHTRINH.INP", "r", stdin);
    freopen("HANHTRINH.OUT", "w", stdout);
    int k, n, m;
    cin >> k >> n >> m;
    vector<road> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i].u >> a[i].v >> a[i].t >> a[i].h;
    int start, end;
    cin >> start >> end;

    vector<ll> d;
    djk(n, start, end, a, k, d);
    return 0;
}
