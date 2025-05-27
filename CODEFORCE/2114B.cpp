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
 * Generated on: 2025-05-26 22:10:40
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__ signed main()

void init() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

__TOISETHIVOI__ {


    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int cnt0 = count(all(s), '0');
        int half = n / 2;
        int x = half - k;
        if (x <= cnt0 && cnt0 <= x + 2 * k && ((cnt0 - x) % 2 == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
