#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void sol() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> f(n);
    f[0] = a[0];
    map<ll, ll> cnt;
    cnt[0]++; 
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] + a[i];
        cnt[f[i]]++;
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += cnt[f[i] - x];
    }
    cout << res;
    return;
}

signed main() {
    sol();
    return 0;
}