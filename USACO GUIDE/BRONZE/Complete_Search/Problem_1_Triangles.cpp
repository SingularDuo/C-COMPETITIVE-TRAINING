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
 * Generated on: 2025-07-09 12:58:02
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
#define __TOISETHIVOI__ signed main()
// bỏ macro vec vì dễ gây lỗi

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 105;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void init() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();

    int n; cin >> n;
    vector<pii> points(n);
    FOR(i, n) cin >> points[i].fi >> points[i].se;

    int res = 0;
    FOR(i, n) FOR(j, n) FOR(k, n) {
        if (i == j || j == k || i == k) continue;

        int x1 = points[i].fi, y1 = points[i].se;
        int x2 = points[j].fi, y2 = points[j].se;
        int x3 = points[k].fi, y3 = points[k].se;

        if ((y1 == y2 && x1 == x3) || (x1 == x2 && y1 == y3)) {
            int base = abs(x1 - x2);
            int height = abs(y1 - y3);
            res = max(res, base * height);
        }
    }

    cout << res << endl;
    return 0;
}
