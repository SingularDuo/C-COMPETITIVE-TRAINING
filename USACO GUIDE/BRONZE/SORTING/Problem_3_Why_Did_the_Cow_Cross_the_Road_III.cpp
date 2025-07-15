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
 * Generated on: 2025-07-11 10:21:57
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



__TOISETHIVOI__ {
    init();
    
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n;
    cin >> n;
    vii cows(n);
    FOR(i, n) cin >> cows[i].first >> cows[i].second;

    sort(cows.begin(), cows.end());

    int cur_time = 0;
    FOR(i, n) {
        int arrive = cows[i].first;
        int duration = cows[i].second;
        if (cur_time < arrive) cur_time = arrive;
        cur_time += duration;
    }

    cout << cur_time << '\n';
    return 0;
}