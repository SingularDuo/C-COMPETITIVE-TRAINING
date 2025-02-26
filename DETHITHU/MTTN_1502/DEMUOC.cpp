#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second

using namespace std;


ll demuoc(ll x) {
    ll count = 0;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            count++;
            if (i != x / i) count++;
        }
    }
    return count;
}
bool isprime(ll n)
{
    if (n <= 1) return false;

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
long long tich(ll x) {
    long long product = 1;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0 && isprime(x)) {
            product *= i;
            if (i != x / i) product *= (x / i);
        }
    }
    return product;
}

signed main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll count = 0;
    for (ll i = 1; i <= n; i++) {
        ll d = demuoc(i);
        long long f = tich(i);
        if (i * f <= n && a <= d && d <= b) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
