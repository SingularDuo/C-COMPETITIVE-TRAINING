#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool various(ll n) {
    ll sum = 1; 
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i; 
        }
    }
    return sum > n; 
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll l, r, res = 0;
    cin >> l >> r;
    for (ll i = l; i <= r; i++) {
        if (various(i)) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
