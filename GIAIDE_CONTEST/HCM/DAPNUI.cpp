#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long

signed main()
{
    int n; cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> l_v(n), l_c(n);
    

    l_c[0] = 0;
    l_v[0] = a[0];

    for(int i = 1; i < n; i++)
    {
        ll v = a[i];
        ll add = 0;
        if (l_v[i-1] >= v)
        {
            add = l_v[i-1] + 1 - v;
            v = l_v[i-1] + 1;
        }
        l_v[i] = v;
        l_c[i] = l_c[i-1] + add;
    }

    vector<ll> r_v(n), r_c(n);
    

    r_c[n-1] = 0;
    r_v[n-1] = a[n-1];

    for(int i = n-2; i >= 0; i--)
    {
        ll v = a[i];
        ll add = 0;

        if (r_v[i+1] >= v)
        {
            add = r_v[i+1] + 1 - v;
            v = r_v[i+1] + 1;
        }
        r_v[i] = v;
        r_c[i] = r_c[i+1] + add;
    }

    ll res = LLONG_MaX;
    for(int i = 1; i < n-1; i++)
    {
        int left_val = l_c[i-1];
        int left_num = l_v[i-1];

        int right_val = r_c[i+1];
        int right_num = r_v[i+1];

        int v = a[i];
        v = max(v, left_num+1);
        v = max(v, right_num+1);

        ll add = v - a[i];
        ll curr = left_val + right_val + add;
        res = min(res, curr);
    }

    cout << res << endl;
}
