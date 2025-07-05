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
 * Generated on: 2025-05-30 23:03:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__ signed main()

void init() {
  freopen("DOANCON.inp", "r", stdin);
  freopen("DOANCON.out", "w", stdout);
  fast;
}
int powmod(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

__TOISETHIVOI__ {
    init();
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = powmod(a[i], m, k);
    }

    map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0, res = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + b[i]) % k;
        if (sum < 0) sum += k;
        res += cnt[sum];
        cnt[sum]++;
    }
    cout<<res<<endl;
    return 0;
}
