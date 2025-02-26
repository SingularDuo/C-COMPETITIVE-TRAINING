#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define KING_PHAT signed main()
#define int long long

KING_PHAT
{
    faster;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> stair(n), step(q);

        for (ll i = 0; i < n; i++)
        {
            cin >> stair[i];
        }
        for (ll i = 0; i < q; i++)
        {
            cin >> step[i];
        }
        vector<ll> max_step(n);
        max_step[0] = stair[0];
        for (int i = 1; i < n; i++) max_step[i] = max(max_step[i - 1], stair[i]);
        vector<ll> f(n);
        f[0] = stair[0];
        for (int i = 1; i < n; i++) 
            f[i] = f[i - 1] + stair[i];
        for (ll i = 0; i < q; i++)
        {
            ll k = step[i];
            ll pos = upper_bound(max_step.begin(), max_step.end(), k) - max_step.begin();

            if (pos == 0) cout << "0 "; 
            else cout << f[pos - 1] << " "; 
        }
        cout << "\n";
    }
}
