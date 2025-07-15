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
 * Generated on: 2025-07-05 20:06:00
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
    int n;
    cin >> n;

    vec(long long, a, n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];


    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    int m;
    cin >> m;

    vec(int, p, m, 0);
    for (int i = 0; i < m; i++) cin >> p[i];

    vector<int> res;

    for (int val : p) {
        if (val > prefix[n]) {
            res.push_back(-1);
            continue;
        }

        int idx = lower_bound(prefix.begin(), prefix.end(), val) - prefix.begin();
        if (idx == 0 || idx > n) {
            res.push_back(-1);
        } else {
            res.push_back(idx);
        }
    }

    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}