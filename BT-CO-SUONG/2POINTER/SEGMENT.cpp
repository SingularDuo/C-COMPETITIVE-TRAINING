#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
bool multitest = false;

void sol()
{
    int n, k;
    cin >> n >> k;  
    vec(ll, a, n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll r = i, minn = a[i], maxx = a[i]; 
        while (r < n && maxx - minn <= k)   
        {
            minn = min(minn, a[r]);
            maxx = max(maxx, a[r]);          
            if (maxx - minn <= k) res++;
            r++;
        }
    }
    cout << res << endl; 
    return;
}

KING_PHAT
{
    I_O("SEGMENT", "SEGMENT");
    multitest = false;
    fast;
    if (multitest)
    {
        int t;
        cin >> t;
        while (t--)
        {
            sol();
        }
    }
    else
    {
        sol();
    }
    return 0;
}
