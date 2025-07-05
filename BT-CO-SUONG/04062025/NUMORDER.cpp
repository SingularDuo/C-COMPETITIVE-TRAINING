/*        _.-- ,.--.
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
void init()
{
    freopen("NUMORDER.inp", "r", stdin);
    freopen("NUMORDER.out", "w", stdout);
    fast;
}
int binpow(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b % 2 == 1) res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

__TOISETHIVOI__ {
    init();
    fast;
    int m, n, k;
    cin >> m >> n >> k;

    vector<int> a;
    a.reserve(m * n);

    for(int i = 1; i <= m; i++) {
        int ii = i * i;
        for(int j = 1; j <= n; j++) {
            int jj = j * j;
            a.push_back(ii + jj);
        }
    }
    nth_element(a.begin(), a.begin() + k - 1, a.end());

    cout << a[k - 1] << "\n";

    return 0;
}
