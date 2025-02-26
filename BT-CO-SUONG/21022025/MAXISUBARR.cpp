#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()
void init()
{
    freopen("MAXISUBARR.INP","r",stdin);
    freopen("MAXISUBARR.OUT","w",stdout);
    faster;
}
KING_PHAT {
    init();
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0), prefix(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i]; 
    }

    ll left = 1, right = n, res = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        bool valid = true;
        for (ll i = mid; i <= n; i++) {
            if (prefix[i] - prefix[i - mid] >= k) { 
                valid = false;
                break;
            }
        }

        if (valid) {
            res = mid;  
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}
