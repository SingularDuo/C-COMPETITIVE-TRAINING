#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

signed main() {
	freopen("FRAC.inp", "r", stdin);
	freopen("FRAC.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    ll limit = min(n, m);
    ll gcd = __gcd(n, m);
    ll mul = limit / gcd;
    ll res = 0;

    for (int i = 1; i <= mul; i++) {
        for (int j = i; j <= mul; j++) {
            if ((n + i * gcd) % (m + j * gcd) == 0) {
                res++;
            }
        }
    }

    cout << res;
}
