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
#define __TOISETHIVOI__ signed main()
const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("SDXDEP.INP", "r", stdin);
  freopen("SDXDEP.OUT", "w", stdout);
  fast;
}
bool ispalin(int n)
{
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int tsnt(int n)
{
    vector<int> prime;
    const int MAX_PRIME = 3162;
    bool isPrime[MAX_PRIME + 1];
    memset(isPrime, true, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_PRIME; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_PRIME; ++i) {
        if (isPrime[i]) {
            while (n % i == 0) {
                prime.push_back(i);
                n /= i;
            }
        }
    }
    if (n > 1) {
        prime.push_back(n);
    }
    sort(prime.begin(), prime.end());
    return unique(prime.begin(), prime.end()) - prime.begin();
}

__TOISETHIVOI__ {
    init();
    int a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = a; i <= b; ++i) {
        if (ispalin(i)) {

            if (tsnt(i) >= 3) {
                res++;
            }
        }
    }

    cout << res;
    return 0;
}
