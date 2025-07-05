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
 * Generated on: 2025-07-03 14:40:53
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
const int MAXN = 1e5;
void init() {
  fast;
}

__TOISETHIVOI__ {
    init();
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> dem(5, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dem[a[i]]++;
    }

    int res = dem[4]; 

    int min13 = min(dem[1], dem[3]);
    res += min13;
    dem[1] -= min13;
    dem[3] -= min13;

    res += dem[3]; 

    res += dem[2] / 2;
    dem[2] %= 2;

    if (dem[2]) {
        if (dem[1] >= 2) {
            res++;
            dem[1] -= 2;
        } else if (dem[1] >= 1) {
            res++;
            dem[1] = 0;
        } else {
            res++;
        }
    }

    res += dem[1] / 4;
    if (dem[1] % 4) res++;
    cout<<res;
    return 0;
}
