#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, k;
vector<ll> a, f;

int main()
{
    cin >> n >> k;

    a.resize(n);
    f.resize(n + 1);

    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i - 1];
        f[i] = f[i - 1] + a[i - 1];
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll target = k + f[i];
        ll l = i + 1, r = n;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (f[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (l <= n) res += n - l + 1;
    }
    cout << res << endl;

    return 0;
}
