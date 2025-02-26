#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll n, a, b;
vector<ll> v;
signed main() {
    cin >> n >> a >> b;
    v.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll need = (n + 1) / 2; 
    cout << need * b + (n - need) * a;
    
    return 0;
}
