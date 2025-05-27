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
    kduckp       |   |./'  :__ \.-'
              '--'
*/
/*
 * Author: kduckp
 * Generated on: 2025-05-26 19:25:17
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long



signed main() {
    freopen("PRIZE.INP", "r", stdin);
    freopen("PRIZE.OUT", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<ll> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    
    ll res = 0;
    int kk = min(m, n);
    for (int k = 1; k <= kk; k++) {
        res = max(res, (ll)k * a[k - 1]);
    }
    
    cout << res;
    return 0;
}
