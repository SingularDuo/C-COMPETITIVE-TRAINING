#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll res = 0;
    int l = 0, r = 0;

    while (r < n) {
        while (r < n) {
            ll minn = *min_element(a.begin() + l, a.begin() + r + 1);
            ll maxx = *max_element(a.begin() + l, a.begin() + r + 1);
            if (abs(maxx - minn) <= k) {
                res += (r - l + 1);
                r++;
            } else {
                break;
            }
        }
        l++;
        if (l > r) r = l;
    }

    cout << res;
}