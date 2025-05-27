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
 * Generated on: 2025-05-16 17:37:02
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
    freopen("Cau1a.inp", "r", stdin);
    freopen("Cau1a.out", "w", stdout);
    fast;
}
ll my_pow(ll a, ll b)
{
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a);
        a = (a * a) ;
        b >>= 1;
    }
    return res;
}
ll calcT(int n)
{
    return my_pow(n, 2) - my_pow(n-1, 2);
}
__TOISETHIVOI__ {
    init();
    int n; cin>>n;
    cout<<n*n;
    return 0;
}