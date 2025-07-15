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
 * Generated on: 2025-07-10 13:22:37
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
  freopen("C.inp", "r", stdin);
  freopen("C.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();

    // your code here
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(i, n) cin >> a[i];

    if(n <= 1e4) {
        while(q--) {
            int l, r, x; cin >> l >> r >> x;
            int res = 0;
            REP(i, l, r) {
                if(a[i - 1] == x) res++;
            }
            cout << res << endl;
        }
        return 0;
    }

    unordered_map<int, vector<int>> pos;
    FOR(i, n) {
        pos[a[i]].pb(i + 1);
    }

    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        auto it = pos.find(x);
        if(it == pos.end()) {
            cout << 0 << endl;
            continue; 
        }
        const vector<int>& v = it->second;
        int cnt = upper_bound(all(v), r) - lower_bound(all(v), l);
        cout << cnt << endl;
    }
}
