#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)

void init() {
    freopen("BAI4_HUB08.inp", "r", stdin);
    freopen("BAI4_HUB08.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll my_pow(ll n, ll k) {
    if (k == 0) return 1;
    if (k == 1) return n;

    ll res = my_pow(n, k / 2);
    res *= res;
    if (k % 2) res *= n;

    return res;
}

signed main() {
    //init();

    ll n, k, s = 0;
    cin >> n;
    vector<ll> a(n + 1), f(n + 1, 0), f_min(n + 1, LLONG_MAX);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        f[i] = f[i - 1] + a[i];
        f_min[i] = min(f_min[i - 1], a[i]);
    }

    ll limit = floor(log2(n)) + 1;
    vector<vector<ll>> dp_f(n+1, vector<ll>(limit));

    // f[i][0] = a[i]
    for (ll i = 1; i <= n; i++) dp_f[i][0] = a[i];

    for (ll k = 1; k < limit; k++) {
        for (ll i = 1; i + int(pow(2, k))-1 <= n; i++) {
            dp_f[i][k] = min(dp_f[i][k - 1], dp_f[i + int(pow(2, k - 1))][k-1]);
        }
    }

    k = (s + 1) / 2;
    ll res = LLONG_MAX;
    ll l = 1;

    for (ll r = 1; r <= n; r++) {
        // cout<<"r: "<<r<<endl;
        while (f[r] - f[l] > k && l <= r) {
            // f[l+1] -> f[r]
            // cout<<l<<" "<<r<<endl;
            l++;
        }
        // while(f[r] - f[l-1] < k)l--;
        // cout<<"done loop"<<endl; 
        // cout<<l<<" "<<r<<endl;
        if (f[r] - f[l - 1] < k) continue;
        // cout<<"valid "<<l<<" "<<r<<endl;

        ll v = f[r] - f[l - 1];
        // cout<<v<<endl;
        if (v == k) {
            // cout<<"v = k"<<endl;
            res = min(res, r - l + 1);
        } else {
            // cout<<"get "<<l<<" "<<r<<endl;
            // cout<<l<<" "<<r<<endl;
            ll du = v - k;
            ll log_range = floor(log2(r - l + 1));
            ll minn = min(dp_f[l][log_range], dp_f[r - int(pow(2, log_range)) + 1 ][log_range]);

            // min[i][k] = min i --> i + 2^k-1
            if (v - minn >= k) res = min(res, r - l);
            else res = min(res, r - l + 1);
        }
    }

    cout << res << endl;
    return 0;
}
