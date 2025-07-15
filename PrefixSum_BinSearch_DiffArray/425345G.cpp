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
 * Generated on: 2025-07-05 20:13:51
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
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vec(int, a, n + 1, 0);
    vec(int, f, n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    int res = 0;
    unordered_map<int, int> countL, countR;

  
    for (int z = n; z >= 1; z--) {
        countR[f[z - 1] + r]++; 

        if (z < n + 1 && f[z - 1] - f[0] > p + q) continue; 
        if (z >= 2) {
            for (int y = 1; y < z; y++) {
               
                if (f[z - 1] - f[y - 1] != q) continue;

                int needL = f[y - 1] - p;
                int needR = f[z - 1] + r;

                res += countL[needL] * countR[needR];
            }
        }

        countL[f[z - 1]]++; 
    }

    cout << res << endl;
    return 0;
}
