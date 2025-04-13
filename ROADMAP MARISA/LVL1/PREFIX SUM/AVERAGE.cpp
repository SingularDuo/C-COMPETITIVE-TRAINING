#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"

signed main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), f(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = (i == 0) ? a[i] : f[i - 1] + a[i];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll val = (i == 0) ? f[j] : f[j] - f[i - 1];
            ll num = j - i + 1;
            if (val % num == 0)
            {
                val = val/num;
                if(val == k)res++;
            }
        }
    }
    cout << res << endl;
}
