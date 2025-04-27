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
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
void sol()
    {
        int n;
        cin>>n;
        vec(ll,a,n,0);
        for(int i = 0; i < n; i++)cin>>a[i];
        int res = 0,l=0;
        for(int r = 0; r < n-1; r++)
        {
            if(a[r] < a[r-1])l = r;
            res = max(res, r - l + 1);
        }
        cout<<res;
    }
    KING_PHAT
{
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    I_O("INCSEG", "INCSEG");
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