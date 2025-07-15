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
 * Generated on: 2025-07-08
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
#define no  cout << "NO\n"

// ========== Custom Macros ==========
#define __TOISETHIVOI__ signed main()
#define vec(a,b,c,d) vector<a> b(c,d)

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void init() {
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    fast;
}

__TOISETHIVOI__ {
    init();

    int n;
    cin >> n;
    vi a(n);
    FOR(i, n) cin >> a[i];

    vi pref(n + 2, 0), suff(n + 2, 0);

    REP(i, 1, n) {
        pref[i] = gcd(pref[i - 1], a[i - 1]);
    }

    FORD(i, n, 1) {
        suff[i] = gcd(suff[i + 1], a[i - 1]);
    }

    int res = 0;
    REP(l, 1, n) {
        REP(r, l, n) {
            int tmp = gcd(pref[l - 1], suff[r + 1]);
            res = max(res, tmp);
        }
    }

    cout << res << endl;
    return 0;
}
