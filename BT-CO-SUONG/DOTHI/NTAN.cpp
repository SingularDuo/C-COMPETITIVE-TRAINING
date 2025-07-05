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
 * Generated on: 2025-07-01 18:07:55
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__ signed main()

void init() {
  fast;
}

__TOISETHIVOI__ {
    init();
    int n;
    cin >> n;

    map<int, int> l, r;

    for (int i = 0; i < 2 * n - 1; i++) {
        int x;
        cin >> x;
        int v = abs(x);
        if (x < 0) {
            l[v]++;
        } else {
            r[v]++;
        }
    }

    set<int> all_sizes;
    for (auto &p : l) all_sizes.insert(p.first);
    for (auto &p : r) all_sizes.insert(p.first);

    for (int v : all_sizes) {
        int cnt_l = l[v];
        int cnt_r = r[v];
        if (abs(cnt_l - cnt_r) == 1) {
            if (cnt_l > cnt_r) {
                cout << -1 << endl << v << endl;
            } else {
                cout << 1 << endl << v << endl;
            }
            return 0;
        }
    }

    return 0;
}