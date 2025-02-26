#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define endl "\n"
ll res = 0;
void gen(ll n, ll start, ll currentlcm) {
    if (n == 0) {
        res = max(res, currentlcm);
        return;
    }
    for (ll i = start; i <= n; i++) {
        ll newlcm = lcm(currentlcm, i);
        gen(n - i, i, newlcm);
    }
}

int main() {
    ll n;
    cin >> n;
    res = 0;
    gen(n, 1, 1);
    cout << res << endl;
    return 0;
}
