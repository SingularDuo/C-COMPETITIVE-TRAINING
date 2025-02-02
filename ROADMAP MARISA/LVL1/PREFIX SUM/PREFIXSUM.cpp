#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    f[0] = a[0];
    for (int i = 1; i < n; i++) f[i] = f[i - 1] + a[i];
    while (k > 0) {
        ll l, r;
        cin >> l >> r;
        if (l == 1) {
            cout << f[r - 1] << endl;
        } else {
            cout << f[r - 1] - f[l - 2] << endl;
        }
        k--;
    }
    return;
}

signed main() {
    sol();
    return 0;
}