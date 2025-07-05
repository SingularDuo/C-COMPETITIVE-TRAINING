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
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
void init()
{
    freopen("UCLN.inp", "r", stdin);
    freopen("UCLN.out", "w", stdout);
    fast;
}
map<int, int> factorize(ll x) {
    map<int, int> mp;
    for (ll i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1) mp[x]++;
    return mp;
}

__TOISETHIVOI__ {
    init();
    fast;

    int n; cin >> n;
    vector<ll> a(n);
    map<int, int> fa;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map<int, int> temp = factorize(a[i]);
        for (map<int, int>::iterator it = temp.begin(); it != temp.end(); ++it) {
            int p = it->first;
            int cnt = it->second;
            fa[p] += cnt;
        }
    }

    int m; cin >> m;
    vector<ll> b(m);
    map<int, int> fb;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
        map<int, int> temp = factorize(b[i]);
        for (map<int, int>::iterator it = temp.begin(); it != temp.end(); ++it) {
            int p = it->first;
            int cnt = it->second;
            fb[p] += cnt;
        }
    }

    ll res = 1;
    for (map<int, int>::iterator it = fa.begin(); it != fa.end(); ++it) {
        int p = it->first;
        int cntA = it->second;

        if (fb.count(p)) {
            int cntB = fb[p];
            int min_exp = min(cntA, cntB);
            for (int i = 0; i < min_exp; i++) {
                res = (res * p) % MOD;
            }
        }
    }

    cout << res << endl;
    return 0;
}
