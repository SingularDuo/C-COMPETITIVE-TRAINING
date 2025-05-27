#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"

signed main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 0, res = LLONG_MIN;

    while (r < n - 1) {
        if (a[r] < a[r + 1]) { 
            r++;
        } else {
            while (l <= r) { 
                ll m = (l + r) / 2; 
                
                if (r - l + 1 >= k) { 
                    res = max(res, a[m]);
                }
                
                l++; 
            }
            r++; 
        }
    }

    while (l < r) {
        if (r - l >= k) { 
            ll m = (l + r) / 2;
            res = max(res, a[m]);
        }
        l++;
    }

    cout << res << endl;
}
