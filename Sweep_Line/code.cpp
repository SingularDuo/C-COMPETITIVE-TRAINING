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
    // name("input.inp", "output.out");
}
struct point
{
    int x,y,id;
    bool operator <(const point& other)
    {
        if(x != other.x)return x < other.x;
        return y < other.y;
    }
};
stuct cmp
{
    bool operator < (const point & a, const point & b) const{
        if(a.y != b.y)return a.y < b.y;
        return a.x < b.x;
    }
};


int binpow(ll a, ll b)
{
    ll res = 1;
    while(b > 0)
    {
        if( b % 2 == 1)res *= a;
        a*=a;
        b/=2;
    }
    return res;
}
ll dist(point a, point b)
{
    return binpow((a.x - b.x),2) + binpow((a.y - b.y), 2);
}
__TOISETHIVOI__ {
    init();
    int n; cin>>n;
    vector<point> a;
    set<point, cmp> s;
    FOR(i, n)
    {
        int x, y; cin>>x>>y;
        a.pb({x,y,i-1});
    }
    sort(all(a));
    ll start = dist(a[0], a[1]);
    int res_1 = 0, res_2 = 0;
    for(auto& i : a)
    {
        int x = i.x, y = i.y, id = i.id;
        int lo = y - d, hi = y + d;

    }
    return 0;
}
