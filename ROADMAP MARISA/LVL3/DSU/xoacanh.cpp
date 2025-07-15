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
 * Generated on: 2025-07-14 14:25:29
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

#define FOR(i, n) for (int i = 0; i < (n); ++i)
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
    // name("input.inp", "output.out");
}

int n,m, q;
const int MAXN = 1e5;
int par[MAXN + 5];
int szz[MAXN + 5];
int sum[MAXN + 5];
vector<pair<int, int>> a;
vector<pair<int, int>> query;
int findset(int u) {
    if (par[u] == u) return u;
    return par[u] = findset(par[u]);
}

void join(int u, int v) {
    u = findset(u);
    v = findset(v);
    //cout<<u<<" "<<v<<'\n';
    if(u == v)return;
    if (szz[u] < szz[v]) swap(u, v);
    par[v] = u;
    szz[u] += szz[v];
}

__TOISETHIVOI__ {
    //init();
    //freopen("i.INP","r",stdin);
    cin >> n >> m >> q;
    a.resize(m);
    query.resize(q);
    REP(i, 1, n) {
        par[i] = i;
        szz[i] = 1;
    }
    vector<bool> deleted(m, false);

    FOR(i, m) cin >> a[i].first >> a[i].second;

    FOR(i, q) {
        cin >> query[i].first >> query[i].second;
        query[i].first--;
        deleted[query[i].first] = true;
    }

//    cout<<q;

    FOR(i, m) {
        if (!deleted[i]) {
            join(a[i].first, a[i].second);
        }
    }
//
    vector<int> res(q);
    //cout<<1;
    PER(i, q - 1, 0) {
        int e = query[i].first;
        int c = query[i].second;
        res[i] = szz[findset(c)];
        //cout<<res[i]<<endl;
        //cout<<e<<'\n';
        join(a[e].fi, a[e].se);

    }
//
//    cout<<q;
        FOR(i, q) cout << res[i] << '\n';

    return 0;
}
