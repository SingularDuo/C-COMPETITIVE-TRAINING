#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long

bool isprime(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3 || x == 5) return true;
    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return false;
    for (int i = 5; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("GOLDBACH.INP", "r", stdin);
    freopen("GOLDBACH.OUT", "w", stdout);

    int n;
    cin >> n;
    while (n--) {
        ll a;
        cin >> a;

        bool found = false;
        if (a > 2 && isprime(a - 2)) {
            cout << 2 << " " << (a - 2) << endl;
            continue;
        }
        for (ll p = 3; p <= a/2; p += 2) {
            if (isprime(p) && isprime(a - p)) {
                cout << p << " " << (a - p) << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
