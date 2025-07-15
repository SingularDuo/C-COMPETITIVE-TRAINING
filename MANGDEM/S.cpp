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
 * Generated on: 2025-07-03 14:16:56
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
  fast;
}

__TOISETHIVOI__ {
    init();
    int n; cin >> n;
    vector<ll> a(n);
    int chan = 0, le = 0, tong = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) chan++;
        else le++;
        tong += a[i];
    }

    // Nếu tổng toàn bộ là chẵn → cần x + y chẵn
    // Nếu tổng toàn bộ là lẻ → cần x + y lẻ
    int res = 0;
    if (tong % 2 == 0) {
        res = chan * (chan - 1) / 2 + le * (le - 1) / 2;
    } 
    else {
        res = chan * le;
    }

    cout << res << endl;
    return 0;
}
