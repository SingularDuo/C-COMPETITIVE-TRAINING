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
 * Generated on: 2025-05-14 13:54:50
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
//#define min(a, b) min((ll)a, (ll)b)
//#define max(a, b) max((ll)a, (ll)b)
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
const int MAXN = 10000;

void init() {
    freopen("BAI3.inp", "r", stdin);
    freopen("BAI3.out", "w", stdout);
    fast;
}


__TOISETHIVOI__  {
    init();
    int n;
    cin >> n;
    vector<pair<int, int>> line(n);
    long long minn = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
        minn = min(minn, line[i].first);
        minn = min(minn, line[i].second);
    }

    if (minn < 0) {
        minn = abs(0 - minn);
        for (int i = 0; i < n; i++) {
            line[i].first += minn;
        }
    }

    vector<int> decart(10000, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= line[i].second; j++) {
            decart[line[i].first + j] = 1;
        }
    }

    long long res = 0;
    for (int i = 0; i < 10000; i++) {
        if (decart[i] == 1) res++;
    }

    cout << res;
    return 0;
}
