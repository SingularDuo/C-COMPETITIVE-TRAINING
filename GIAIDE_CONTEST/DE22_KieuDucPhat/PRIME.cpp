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
#define lb lower_bound
#define ub upper_bound
#define debug(x,y) cout<<x<<" "<<y<<endl;

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;
const int MAXN = 1e6 + 5;

bool isprime[MAXN];
vector<int> primes, dpk;

void sieve() {

    fill(isprime, isprime + MAXN, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i < MAXN; ++i)
        if (isprime[i])
            for (int j = i * i; j < MAXN; j += i)
                isprime[j] = false;

    for (int i = 2; i < MAXN; ++i)
        if (isprime[i]) primes.pb(i);

    //cout<<primes.size()<<endl;
    for (int i = 0; i < (int)primes.size(); ++i) {
        for (int j = i + 1; j < (int)primes.size(); ++j) {
            int mul = primes[i] * primes[j];
            if (mul > 1e6) break;
            dpk.pb(mul);
        }
    }

    sort(all(dpk));
}

__TOISETHIVOI__ {
    freopen("PRIME.inp", "r", stdin);
    freopen("PRIME.out", "w", stdout);

    fast;

    sieve();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        auto it = upper_bound(all(dpk), n);
        if (it != dpk.begin()) {
            it--;
            cout << *it << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
