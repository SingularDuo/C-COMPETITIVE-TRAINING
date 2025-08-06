#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;    
const int INF = 2 * 1e18;
const int MAXN = 5 * 1e6;

bool is_prime[MAXN + 5];
int min_dist[MAXN + 5];

void init() {

    fill(is_prime, is_prime + MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;


    int last_prime = -INF;
    for (int i = 0; i <= MAXN; ++i) {
        if (is_prime[i]) {
            last_prime = i;
            min_dist[i] = 0;
        } else {
            min_dist[i] = i - last_prime;
        }
    }


    int next_prime = INF;
    for (int i = MAXN; i >= 0; --i) {
        if (is_prime[i]) {
            next_prime = i;
            min_dist[i] = 0;
        } else {
            min_dist[i] = min(min_dist[i], next_prime - i);
        }
    }
}

__TOISETHIVOI__ {
    fast;
    init();

    int n, k;
    cin >> n >>k;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += min_dist[x];
    }
    cout << res << endl;

    return 0;
}