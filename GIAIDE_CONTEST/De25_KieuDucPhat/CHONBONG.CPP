#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init() {
  freopen("ChonBong.inp", "r", stdin);
  freopen("ChonBong.out", "w", stdout);
  fast;
}
signed main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> cnt(k + 1, 0);
    for (ll i = 0; i < n; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }
    ll S = n;
    ll M = 0;
    for (ll i = 1; i <= k; i++) {
        if (cnt[i] > M) M = cnt[i];
    }
    ll sum = S - M;
    ll ans;
    if (M > sum) {
        ans = 2 * sum;
    }
    else {
        ans = S - (S % 2);
    }

    cout << ans;
    return 0;
}
