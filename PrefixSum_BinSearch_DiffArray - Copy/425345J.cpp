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
 * Generated on: 2025-07-05 20:27:17
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
    int n, k; cin>>n>>k;
    vec(int, a, n, 0);
    for(int i = 0; i < n; i++)cin>>a[i];

    vec(int, f, n, 0);
    f[0] = a[0];
    for(int i = 1; i < n; i++)f[i]  = f[i-1] + a[i];
    int res = 0;
    for (int i = 0; i < n; i++) {
        int target = (i == 0) ? k : f[i - 1] + k;
        auto it = upper_bound(f.begin() + i, f.end(), target);
        res += (it - (f.begin() + i)); 
    }
    cout<<res;
    return 0;
}