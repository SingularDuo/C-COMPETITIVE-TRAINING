#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; ++i) cin >> a[i];  
    for (ll i = 1; i <= n; i++) {
        ll target = -1 * a[i];
        for (ll j = 1; j <= n; j++) {
            if (a[j] == target) {
                cout << i << " " << j << endl;  
                return 0;
            }
        }
    }
    return 0;
}
