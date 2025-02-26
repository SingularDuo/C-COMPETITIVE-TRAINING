#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAXN = 200000;

ll fact[MAXN + 1], inv_fact[MAXN + 1];
ll power(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAXN] = power(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i > 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}
ll comb(ll n, ll k) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        cout << comb(n + m - 1, m) << "\n";
    }
    return 0;
}
