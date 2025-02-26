#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

ll res = 0;

void gen(const vector<ll>& a, vector<ll>& group, ll i) {
    if (i == 0) {
        ll lx1 = 1, lx2 = 1;
        for (ll j = 0; j < (ll)a.size(); j++) {
            if (group[j] == 0) lx1 *= a[j];
            else lx2 *= a[j];
        }
        if (__gcd(lx1, lx2) == 1) res++;
        return;
    }
    group[i] = 0;
    gen(a, group, i -1);
    group[i] = 1;
    gen(a, group, i -1);
    return;
}


signed main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        res = 0; 
        vector<ll> group(n, 0);
        gen(a, group, n);

        cout << res << '\n'; 
    }
}
