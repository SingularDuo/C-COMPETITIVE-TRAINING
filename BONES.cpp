#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool enough(ll w, ll l, ll x, ll add) {
    double val = 1.0 * (w + add) / (w + l + add);
    return val >= x / 100.0;
}
int main() {
    ll w, l, x;
    cin >> w >> l >> x;

    ll le = 0, r = 1e9, ans = -1;
    while (le <= r) {
        ll mid = (le + r) / 2;
        if (enough(w, l, x, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            le = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
