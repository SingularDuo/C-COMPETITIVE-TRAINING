#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll min_val = a[0];
    ll max_diff = LLONG_MIN;

    for (ll j = 1; j < n; ++j) {
        max_diff = max(max_diff, a[j] - min_val);
        min_val = min(min_val, a[j]);
    }
    cout << max_diff << endl;
    return 0;
}
