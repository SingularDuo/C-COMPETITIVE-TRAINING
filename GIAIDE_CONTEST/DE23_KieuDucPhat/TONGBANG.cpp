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
#define ull unsigned ll
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1532023;
const int InF = 2 * 1e18;

void init() {
  freopen("TONGBANG.inp", "r", stdin);
  freopen("TONGBANG.out", "w", stdout);
  fast;
}


ll sumr(int i, int n) {
    ll base = (ll)(i - 1) * n;
    ll k;
    ll first, last;

    if (i % 2 == 1) {
        k = (n + 1) / 2;
        first = base + 1;
        last = base + 2 * k - 1;
    } else {
        k = n / 2;
        first = base + 2;
        last = base + 2 * k;
    }
    ll total = k * (first + last) / 2;
    return total % MOD;
}

__TOISETHIVOI__{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    ll res = 0;

    for (int i = 1; i <= m; ++i) {
        res = (res + sumr(i, n)) % MOD;
    }
    cout << res;
    return 0;
}
