#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5;
vector<bool> isprime(maxn + 5, true);

void sieve() {
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

bool dx(ll x) {
    if (x <= 9 && isprime[x]) return true;
    string s = to_string(x);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return isprime[x] && s == rev;
}

int main() {
    freopen("SUMOFPRIMES.inp", "r", stdin);
    freopne("SUMOFPRIMES.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();

    ll t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        for (ll i = l; i <= r; i++) {
            if (dx(i)) {
                res += i;
            }
        }
        cout << res << endl;
    }
    return 0;
}
