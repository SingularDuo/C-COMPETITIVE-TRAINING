#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void init() {
    freopen("CHIAK.inp", "r", stdin);
    freopen("CHIAK.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    vector<ll> prefix(n + 1, 0);
    map<ll, ll> cnt;

    cnt[0] = 1;
    ll soluong = 0;

    for (ll i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
        ll mod_val = (prefix[i] % k + k) % k;
        soluong += cnt[mod_val];
        cnt[mod_val]++;
    }

    cout << soluong << endl;
}
