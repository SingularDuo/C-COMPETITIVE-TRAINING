#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            ll curri = i *a[i];
            for (ll j = i + 1; j < n; j++) {
                ll currj = j * a[j];
                if (curri > currj) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


/**
 2
 7
 5 0 10 2 4 1 6
 4 
 8 4 2 1

 */
