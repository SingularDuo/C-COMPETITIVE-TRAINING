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
 * Generated on: 2025-05-30 23:03:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}
const int MAXN = 1e6;
vector<ll> a(MAXN, 0);
__TOISETHIVOI__ {
    //init();
    int n, r; cin >> n >> r;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x >= 0 && x < MAXN) a[x] = y;
    }

    vector<ll> f(MAXN, 0);
    f[0] = a[0];
    for(int i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] + a[i];
    }

    int res = LLONG_MIN;
    for(int i = 0; i < MAXN; i++) {
        int l = max(0LL, i - r);
        int rpos = i + r;
        if (rpos >= MAXN) rpos = MAXN;
        int v = f[rpos] - (l > 0 ? f[l - 1] : 0);
        res = max(res, v);
    }

    cout << res;
    return 0;
}
