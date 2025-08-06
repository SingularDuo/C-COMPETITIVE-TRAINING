#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for (int i = 1; i <= (n); ++i)

const int MAXN = 1e5 + 5;

int par[MAXN], szz[MAXN];

int findset(int u) {
    if (par[u] == u) return u;
    return par[u] = findset(par[u]);
}

void join(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return;
    if (szz[u] < szz[v]) swap(u, v);
    par[v] = u;
    szz[u] += szz[v];
}

#define __TOISETHIVOI__ signed main()
__TOISETHIVOI__ {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vii edges(m + 1);
    FOR(i, m) cin >> edges[i].first >> edges[i].second;

    vi del(q + 1);
    vector<bool> to_del(m + 1, false);
    FOR(i, q) {
        cin >> del[i];
        to_del[del[i]] = true;
    }

    FOR(i, n) {
        par[i] = i;
        szz[i] = 1;
    }

    int comps = n;

    FOR(i, m) {
        if (!to_del[i]) {
            int u = edges[i].first, v = edges[i].second;
            if (findset(u) != findset(v)) {
                join(u, v);
                comps--;
            }
        }
    }

    vi res;

    for (int i = q; i >= 1; i--) {
        res.push_back(comps);
        int idx = del[i];
        int u = edges[idx].first, v = edges[idx].second;
        if (findset(u) != findset(v)) {
            join(u, v);
            comps--;
        }
    }

    reverse(all(res));
    for (int x : res) cout << x << '\n';

    return 0;
}
