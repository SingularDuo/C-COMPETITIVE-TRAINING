#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void init()
{
    freopen("DAYCON.inp", "r", stdin);
    freopen("DAYCON.out", "w", stdout);
    fast;
}
KING_PHAT
{
    fast;
    init();
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // sub1 + sub2 n <= 1e3 = 90%
    if(n <= 1000)
    {
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            ll currsum = a[i];
            if(currsum >= k) res++;
            for(int j = i+1; j < n; j++)
            {
                currsum += a[j];
                if(currsum >= k) res++;
            }
        }
        cout << res;
        return 0;
    }
    ll res = 0, left = 0, currsum = 0;
    for(ll right = 0; right < n; right++)
    {
        currsum += a[right];
        while(currsum >= k)
        {
            res += (n - right); 
            currsum -= a[left++];
        }
    }
    cout << res;
    return 0;
}
