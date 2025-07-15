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
 * Generated on: 2025-07-05 19:55:44
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
#define vec(a,b,c,d) vector<a> b(c,d)

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  //freopen("input.inp", "r", stdin);
  //freopen("output.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    init();
    int n, p; cin >> n >> p;
    vec(int, a, n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, int> mp;
    int sum = 0, res = 0;
    mp[0] = 1; 

    for (int i = 0; i < n; i++) {
        sum += a[i];
        res += mp[sum - p]; 
        mp[sum]++;
    }

    cout << res << endl;
    return 0;
}
