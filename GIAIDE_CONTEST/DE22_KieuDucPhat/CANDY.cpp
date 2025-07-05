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

void init() {
  freopen("CANDY.inp", "r", stdin);
  freopen("CANDY.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    //init();
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> a;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push({x, i});
    }

    while (m > 0) {
        pair<int, int> v = a.top();
        a.pop();
        v.first++;
        a.push(v);
        m--;
    }

    vector<ll> res(n);
    while (!a.empty()) {
        pair<int, int> v = a.top();
        a.pop();
        res[v.second] = v.first;
    }

    for (auto& i : res) cout << i << " ";
    return 0;
}
