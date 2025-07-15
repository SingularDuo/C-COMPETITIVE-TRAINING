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
 * Generated on: 2025-07-14 20:03:17
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define vii vector<pii>
#define FOR(i, n) for (int i = 1; i <= (n); ++i)

const int INF = 2e18;
const int MAXN = 1005;
int par[MAXN], szz[MAXN];
int n;
vii a;

int findset(int u) {
    if (u == par[u]) return u;
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


int dist_calc(pii a, pii b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool checkValid(int check) {

    FOR(i, n) {
        par[i] = i;
        szz[i] = 1;
    }
    FOR(i, n) {
        for (int j = i + 1; j <= n; ++j) {
            if (dist_calc(a[i], a[j]) <= check) {
                join(i, j);
            }
        }
    }
    int root = findset(1);
    FOR(i, n) {
        if (findset(i) != root)
            return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> n;
    a.resize(n + 1);
    FOR(i, n) cin >> a[i].first >> a[i].second;

    int lo = 0, hi = 1e9, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (checkValid(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
