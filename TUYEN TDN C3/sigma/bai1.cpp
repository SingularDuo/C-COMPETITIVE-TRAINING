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
 * Generated on: 2025-07-10 13:20:56
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

// ========== short Macros ==========
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

// ========== Output shortcuts ==========
#define yes cout << "YEs\n"
#define no cout << "NO\n"

// ========== Custom Macros ==========
#define __TOIsETHIVOI__ signed main()
#define vec(a,b,c,d) vector<a> b(c,d)

// ========== Constants ==========
const int MOD = 1e9 + 7;
const int INF = 2e18;
const int N = 2e5 + 5;
const int LOG = 20;
const double PI = acos(-1);
const double EPs = 1e-9;

// ========== Debug Helper ==========
// #define debug(x) cerr << #x << " = " << x << endl;

void init() {
  freopen("S.inp", "r", stdin);
  freopen("S.out", "w", stdout);
  fast;
}

__TOIsETHIVOI__ {
    init();

    int n, s;
    cin >> n >> s;
    vec(int, a, n, 0);
    FOR(i, n) cin >> a[i];

    int l = 0, r = 0;
    int sum = 0, res = -1;

    while (r < n) {
        sum += a[r];

        while (l <= r && sum > s) {
            sum -= a[l];
            l++;
        }

        if (sum <= s)
            res = max(res, r - l + 1);

        r++;
    }

    cout << (res > 0 ? res : -1) << endl;
    return 0;
}
