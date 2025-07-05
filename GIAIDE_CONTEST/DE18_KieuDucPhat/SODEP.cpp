/*        _.-- ,.--.
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
const int InF = 2 * 1e18;

void init() {
  freopen("SODEP.inp", "r", stdin);
  freopen("SODEP.out", "w", stdout);
  fast;
}

int cnt(int n) {
    int div = 1;
    int exp = 0;
    while (n % 2 == 0) {
        exp++;
        n /= 2;
    }
    div *= (exp + 1);
    for (int i = 3; i * i <= n; i += 2) {
        exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        div *= (exp + 1);
    }
    if (n > 1) {
        div *= 2;
    }
    return div;
}

__TOISETHIVOI__ {
    init();
    int n; cin >> n;
    cout << cnt(n) << endl;
    return 0;
}
