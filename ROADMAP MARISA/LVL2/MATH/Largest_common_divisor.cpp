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
ll my_pow(int n, int k, int mod = 1e9 + 7)
{
    if(k == 0) return 1 % mod;
    if(k == 1) return n % mod;

    ll res = my_pow(n, k/2, mod);
    res = res * res % mod;
    if(k % 2 == 1) res *= n;
    return res % mod;
}
const int MOD = 1e9+7;
int highest_power(int &x, int p)
{
    int exp = 0;
    while(x % p == 0)
    {
        exp++;
        x /= p;
    }
    return exp;
}
// legendre
void sol()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> luu_tsnt; 
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        for(int j = 2; j * j <= x; j++)
        {
            int exp = highest_power(x, j);
            luu_tsnt[j] = max(luu_tsnt[j], exp);
        }
        if(x > 1)
        {
            luu_tsnt[x] = max(luu_tsnt[x], 1);
        }
    }

    ll lcm_result = 1;
    for(auto& i  : luu_tsnt)
    {
        lcm_result = (lcm_result * my_pow(i.fi, i.se) % MOD )%MOD ;
    }

    cout << lcm_result << endl;
}
KING_PHAT
{
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
