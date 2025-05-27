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
 * Generated on: 2025-05-17 22:34:18
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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
ll c(ll x) {
    if (x <= 1) return 0;
    return 64 - __builtin_clzll(x - 1);
}

__TOISETHIVOI__{
    int t; cin>>t;
    while(t--)
    {
         ll n, m, a, b;
        cin >> n >> m >> a >> b;

        ll a1 = min(n - a + 1, a);
        ll b1 = min(m - b + 1, b);

        ll ch = 1 + c(m) + c(a1);
        ll cb = 1 + c(n) + c(b1);

        cout << min(ch, cb) << endl;
    }

    return 0;
}