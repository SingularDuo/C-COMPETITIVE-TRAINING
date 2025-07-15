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
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'

#define FOR(i, n) for (int i = 1; i <= (n); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define YESNO(x) cout << ((x) ? "YES\n" : "NO\n")

#define bitcount(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)

#define debug(x)
#define lb lower_bound
#define ub upper_bound

#define __TOISETHIVOI__ signed main()
#define vec(a, b, c, d) vector<a> b(c, d)
#define allin(a, x) (find(all(a), x) != (a).end())
#define vec2d(type, name, r, c, val) vector<vector<type>> name((r), vector<type>((c), (val)))
#define vec3d(type, name, x, y, z, val) vector<vector<vector<type>>> name((x), vector<vector<type>>((y), vector<type>((z), (val))))

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void name(const string &inFile, const string &outFile) {
    freopen(inFile.c_str(), "r", stdin);
    freopen(outFile.c_str(), "w", stdout);
}

void init() {
    fast;
    name("wormsort.in", "wormsort.out");
}

struct wormhole {
    int u, v, w;
    bool operator < (const wormhole &other) const {
        return w < other.w;
    }
};

const int MAXN = 1e5;
int par[MAXN + 5];
int szz[MAXN + 5];

int findset(int u) {
    if (u == par[u]) return u;
    return par[u] = findset(par[u]);
}

void join(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return;
    if (u > v) swap(u, v);
    szz[u] += szz[v];
    par[v] = u;
}

__TOISETHIVOI__ {

    init();

    FOR(i, MAXN) {
        par[i] = i;
        szz[i] = 1;
    }

    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    FOR(i, n) cin >> a[i];

    vector<wormhole> b(m);
    int maxx = -INF;
    FOR(i, m) {
        cin >> b[i - 1].u >> b[i - 1].v >> b[i - 1].w;
        maxx = max(maxx, b[i - 1].w);
    }

    sort(all(b));

    int start = m;
    for (int i = n; i >= 1; i--) {
        while (start > 0 && findset(i) != findset(a[i])) {
            start--;
            join(b[start].u, b[start].v);
        }
    }

    cout << (start == m ? -1 : b[start].w);
    return 0;
}
