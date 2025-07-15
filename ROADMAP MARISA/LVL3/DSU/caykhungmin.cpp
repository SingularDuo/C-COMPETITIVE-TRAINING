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
 * Generated on: 2025-07-14 15:21:43
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
const int MAXN = 1e5;
int par[MAXN + 5];
int szz[MAXN + 5];
int findset(int u)
{
    if(par[u] == u)return u;
    return par[u] = findset(par[u]);
}
void join(int u, int v)
{
    u = findset(u);
    v = findset(v);
    if(u == v)return;
    if(szz[u] < szz[v])swap(u, v);
    par[v] = u;
    szz[u] += szz[v];
}
struct node
{
    int u, v, w;
};
bool cmp(node a, node b)
{
    return a.w < b.w;
}
__TOISETHIVOI__ {
    init();
    int n, m; cin>>n>>m;
    vector<node> a(m);
    FOR(i, m)cin>>a[i].u>>a[i].v>>a[i].w;
    sort(all(a), cmp);
    FOR(i, MAXN)
    {
        par[i] = i;
        szz[i] = 0;
    }
    int minn = 0;
    int used = 0;

    for (int i = 0; i < m; i++) {
        int u = a[i].u;
        int v = a[i].v;
        int w = a[i].w;

        if (findset(u) != findset(v)) {
            join(u, v);
            minn += w;
            used++;
            if (used == n - 1) break;
        }
    }
    
    cout << minn << endl;


    return 0;
}
