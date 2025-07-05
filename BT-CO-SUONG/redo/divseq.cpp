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
__TOISETHIVOI__ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int d, n; cin >> d >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        map<int, int> cnt;
        cnt[0] = 1;
        int prefix_mod = 0;
        int res = 0;

        for(int i = 0; i < n; i++) {
            prefix_mod = (prefix_mod + a[i] % d) % d;
            if(cnt.count(prefix_mod)) {
                res += cnt[prefix_mod];
            }
            cnt[prefix_mod]++;
        }
        cout << res<<endl;
    }
    return 0;
}
