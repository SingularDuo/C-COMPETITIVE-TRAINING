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
 * Generated on: 2025-07-07 20:05:01
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
#define __TOISETHIVOI__ signed main;
#define vec(a,b,c,d) vector<a> b(c,d)

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

// ========== Debug Helper ==========
// #define debug(x) cerr << #x << " = " << x << endl;

void init() {
  //freopen("input.inp", "r", stdin);
  //freopen("output.out", "w", stdout);
  fast;
}


signed main() {
    init();

    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, n) cin >> a[i];

    vii query(q);
    FOR(i, q) cin >> query[i].first >> query[i].second;

    vi f(n, 0);
    f[0] = a[0];
    REP(i, 1, n-1) f[i] = f[i-1] + a[i];

    FOR(i, q) {
        int l = query[i].first - 1;
        int r = query[i].second - 1;

        int lo = l, hi = r;
        int min_diff = INF;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int sum_left = f[mid] - (l ? f[l - 1] : 0);
            int sum_right = f[r] - f[mid];

            min_diff = min(min_diff, abs(sum_left - sum_right));

            if (sum_left < sum_right)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        cout << min_diff << endl;
    }

    return 0;
}