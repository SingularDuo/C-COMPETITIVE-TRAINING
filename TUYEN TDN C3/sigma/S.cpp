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
 * Generated on: 2025-07-10 16:02:44
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

__TOISETHIVOI__ {
    init();

    int n, k; cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vi p(n + 1, 0), p_max(n + 1, -INF); 
    p_max[1] = 0; 
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
        p_max[i] = max(p[i], p_max[i - 1]);
    }

    if (p[n] <= k) {
        cout << n;
        return 0;
    }

    int res = 0;
    for (int r = 1; r <= n; r++) {
        int need = p[r] - k;

        int lo = 1, hi = r - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            //cerr << "r: " << r << " " << "mid:" << mid << " p_max: " << p_max[mid] << ' ' << p[r] << ' ' << k << endl;
            if (p_max[mid] >= need) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        //cerr << "ans: " << ans << endl;
        if (ans != -1) {
            int l = ans + 1;
            res = max(res, r - l + 1);
        }
    }

    cout << res << '\n';

    return 0;
}
