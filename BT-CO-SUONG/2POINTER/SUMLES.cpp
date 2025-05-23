#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
bool multitest = false;
void init()
{
    freopen("SUMLES.inp", "r", stdin);
    freopen("SUMLES.out", "w", stdout);
    fast;
}
void sol()
{
    int n, s;
    cin >> n >> s;
    vec(ll, a,n,0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, current = 0, res = 0;
    for (int r = 0; r < n; r++)
    {
        current += a[r];
        while (current > s && l <= r)
        {
            current -= a[l];
            l++;
        }
        res = max(res, r - l + 1);
    }
    cout << res << endl;
}
KING_PHAT
{
    // set state for multitest
    // multitest = true;
    init();
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
