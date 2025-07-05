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
 * Generated on: 2025-07-03 10:01:30
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
int d[10010];

int get(int x) {
    if (d[x] != x) d[x] = get(d[x]);
    return d[x];
}

void init() {
    
    fast;
}

__TOISETHIVOI__ {
    init();
    int n, q, x, y, c;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) d[i] = i;
    for (int i = 2; i <= n; i++) {
        cin >> x >> c;
        y = i;
        if (c == 1) {
            x = get(x); y = get(y);
            if (x != y) d[y] = x;
        }
    }
    while (q--) {
        cin >> x >> y;
        cout << (get(x) == get(y) ? "NO" : "YES") << endl;
    }
    return 0;
}
