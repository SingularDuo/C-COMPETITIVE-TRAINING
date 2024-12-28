#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll maxn = 1e6 + 1;
const ll MOD = 1e9 + 7;

bool isprime[maxn + 1];
ll a[maxn + 5];

void sieve() {
    for (ll i = 0; i <= maxn; i++) isprime[i] = true;
    isprime[1] = isprime[0] = false;
    for (ll i = 2; i * i <= maxn; i++) {
        if (isprime[i]) {
            for (ll j = i * i; j <= maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll b;
        cin >> b;
        if (isprime[b]) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }
    ll minn = LLONG_MAX;
    bool found_prime_pair = false;
    for (ll i = 1; i <= n; i++) {
        if (a[i] == 1) {
            for (ll j = i + 1; j <= n; j++) {
                if (a[j] == 1) {
                    ll diff = j - i + 1;
                    minn = min(minn, diff);
                    found_prime_pair = true; 
                }
            }
        }
    }
    if (!found_prime_pair) {
        cout << -1 << endl;
    } else {
        cout << minn << endl;
    }

    return 0;
}
