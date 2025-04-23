#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
const int maxn = 1e5;

void init() {
    freopen("SGAME.INP", "r", stdin);
    freopen("SGAME.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main() {
    init();
    int n;
    cin >> n;
    vector<ll> b(n), c(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll res = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(c.begin(), c.end(), -b[i]);
        if (it != c.end()) {
            res = min(res, abs(b[i] + *it));
        }
        if (it != c.begin()) {
            res = min(res, abs(b[i] + *(it - 1)));
        }
    }
    cout << res << '\n';
    return 0;
}
