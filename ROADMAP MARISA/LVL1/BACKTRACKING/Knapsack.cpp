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
 * Generated on: 2025-05-14 12:30:34
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
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
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

ll n, w;
vector<ll> weight, value;
unordered_map<ll, unordered_map<ll, ll>> memo;

ll knapsack(ll idx, ll rem) {
    if (idx == n) return 0;
    if (memo[idx].find(rem) != memo[idx].end()) return memo[idx][rem];

    ll best = knapsack(idx + 1, rem);
    if (rem >= weight[idx]) {
        best = max(best, knapsack(idx + 1, rem - weight[idx]) + value[idx]);
    }
    return memo[idx][rem] = best;
}

__TOISETHIVOI__ {
    cin >> n >> w;
    weight.resize(n);
    value.resize(n);
    for (ll i = 0; i < n; i++) cin >> weight[i] >> value[i];

    cout << knapsack(0, w) << endl;
    return 0;
}
