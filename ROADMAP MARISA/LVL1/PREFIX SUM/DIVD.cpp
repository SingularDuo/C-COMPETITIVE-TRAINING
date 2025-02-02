#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void bruteforce(ll n, ll d) // 10^4
{
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> f(n);
    f[0] = a[0];
    ll cnt = 0;

    for (ll i = 1; i < n; i++) f[i] = f[i - 1] + a[i];

    for (ll l = 0; l < n; l++) {
        for (ll r = l; r < n; r++) {
            ll current = f[r] - (l > 0 ? f[l - 1] : 0);
            if (current % d == 0) cnt++;
        }
    }
    cout << cnt << endl;
}

void optimize(ll n, ll d) {
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll cnt = 0;
    ll prefix_sum = 0;
    map<ll, ll> m;
    m[0] = 1;

    for (ll i = 0; i < n; i++) {
        prefix_sum = (prefix_sum + a[i]) % d;
        if (prefix_sum < 0) prefix_sum += d;

        cnt += m[prefix_sum]; 
        m[prefix_sum]++;
    }
    cout << cnt << endl;
}

signed main() {
    ll n, d;
    cin >> n >> d;
    if (n <= 1e4) {
        bruteforce(n, d);
    } else {
        optimize(n, d);
    }
    return 0;
}
