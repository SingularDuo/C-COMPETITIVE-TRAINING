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
 * Generated on: 2025-05-16 18:39:46
*/

#include <bits/stdc++.h>
using namespace std;

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
const int MAXN = 300000;

void init() {
        freopen("Cau2b.inp", "r", stdin);
        freopen("Cau2b.out", "w", stdout);
        fast;
}

vector<bool> is_prime(MAXN + 1, true);
vector<int> prime;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (is_prime[i]) {
            prime.pb(i);
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = sqrt(MAXN) + 1; i <= MAXN; ++i) {
        if (is_prime[i]) {
            prime.pb(i);
        }
    }
}

int cnts(int n) {
    int count = 0;
    for (int u : prime) {
        if (u >= n) break;
        int v = n - u;
        if (u < v && v <= MAXN && is_prime[v]) {
            count++;
        }
    }
    return count;
}

__TOISETHIVOI__ {
    init();
    sieve();
    int n;
    cin >> n;
    cout << cnts(n) << endl;
    return 0;
}
