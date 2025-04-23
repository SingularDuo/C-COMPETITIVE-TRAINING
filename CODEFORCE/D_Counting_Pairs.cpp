#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    //adasdada
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            ll least = sum - y - a[i];
            ll maxx = sum - x - a[i];
            auto lower = lower_bound(a.begin() + i + 1, a.end(), least);
            auto upper = upper_bound(a.begin() + i + 1, a.end(), maxx);
        
            res += (upper - lower);
        }
        
        cout << res << endl;
    }
}