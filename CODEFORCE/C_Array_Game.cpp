#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (k >= 3) {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        ll res = LLONG_MAX; 
        
        for (int i = 1; i < n; i++) {
            res = min(res, a[i] - a[i - 1]);
        }

        if (k == 1) {
            cout << res << endl;
            continue;
        } 
        
        if (k == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    ll val = a[i] - a[j];
                    auto it = lower_bound(a.begin(), a.end(), val);
                    if (it != a.end()) {
                        res = min(res, *it - val);
                    }
                    if (it != a.begin()) {
                        res = min(res, val - *(it - 1));
                    }
                }
            }
            cout << res << endl;
        }
    }
}
