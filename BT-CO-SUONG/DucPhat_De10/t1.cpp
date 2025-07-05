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

int binpow(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if(b % 2 == 1)res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

int m, n, k;

int count_le(int x) {
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int remain = x - i * i;
        if (remain < 1) break;
        int j = sqrt(remain);
        cnt += min(n, j);
    }
    return cnt;
}

__TOISETHIVOI__ {
    fast;
    cin >> m >> n >> k;
    if (m * n <= 1e7) {
        vector<int> res;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                res.pb(binpow(i, 2) + binpow(j, 2));
            }
        }
        sort(all(res));
        cout << res[k - 1];
    } else {
        if (m > n) swap(m, n);
        int l = 2, r = m * m + n * n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (count_le(mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        cout << ans;
    }
    return 0;
}
