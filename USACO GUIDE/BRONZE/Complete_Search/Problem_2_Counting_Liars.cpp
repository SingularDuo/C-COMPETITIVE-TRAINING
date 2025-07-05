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
 * Generated on: 2025-07-02 15:57:40
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
    //init();
    int n;
    cin >> n;

    vector<pair<char, int>> a(n);
    vector<int> val;

    for(int i = 0; i < n; i++) {
        char t;
        int x;
        cin >> t >> x;
        a[i] = {t, x};
        val.pb(x);
    }

    sort(all(val));
    val.erase(unique(all(val)), val.end());

    int res = n;
    for(int x : val) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i].fi == 'L' && a[i].se < x) cnt++;
            if(a[i].fi == 'G' && a[i].se > x) cnt++;
        }
        res = min(res, cnt);
    }

    cout << res << endl;
    return 0;
}
