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
 * Generated on: 2025-07-09 15:09:15
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
#define vec(a,b,c,d) vector<a> b(c,d)

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 1e3 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPS = 1e-9;

void init() {
  //freopen("lifeguards.in", "r", stdin);
  //freopen("lifeguards.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    fast;

    int n;
    cin >> n;
    vector<pii> shifts(n);
    FOR(i, n) cin >> shifts[i].fi >> shifts[i].se;

    int res = 0;

    FOR(skip, n) {
        
        vi timeline(1001, 0);

        FOR(i, n) {
            if (i == skip) continue;
            int l = shifts[i].fi;
            int r = shifts[i].se;
            for (int t = l; t < r; ++t) {
                timeline[t] = 1;
            }
        }

        int covered = accumulate(all(timeline), 0LL);
        res = max(res, covered);
    }

    cout << res << endl;
    return 0;
}
