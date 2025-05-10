#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
bool multitest = false;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
ll my_pow(int n, int k)
{
    if(k == 0) return 1 ;
    if(k == 1) return n ;

    ll res = my_pow(n, k/2);
    res = res * res ;
    if(k % 2 == 1) res *= n;
    return res ;
}
void sol()
{
    int n;
    cin>>n;
    int k = 2, exp = 1;
    while(k  + my_pow(3, exp)<=n)
    {
        k += my_pow(3, exp); // tim so dau tien cua luot boc tiep theo
        exp++;
    }
    cout<<k;
}
KING_PHAT
{
    //gen_start();
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
        sol();
    }
    return 0;
}