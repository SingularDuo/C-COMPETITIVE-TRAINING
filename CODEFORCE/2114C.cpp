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
 * Generated on: 2025-05-26 22:16:13
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const ll INF = 2LL * 1e18;

__TOISETHIVOI__ {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll last = -INF;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > last + 1) {

                ans++;
                last = a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
