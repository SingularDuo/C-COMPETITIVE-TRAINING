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
    cout<<1;
    int n;
    cin>>n;
    vec(ll,a,n,0);
    vec(ll,b,n,0);
    for(int i  = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < n; i++)cin>>b[i];
    sort(all(a));\\\
    sort(all(b));
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        int current = 0;
    }
}
KING_PHAT
{
    multitest = false;
    // set state for multitest
    // multitest = true;
    //set state for I/O style
    //I_O("test1", "test1");
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
        cout<<2;
        sol();
    }
    return 0;
}