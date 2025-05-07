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
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
bool multitest = false;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}
const int MOD = 1e9+7;
int highest_power(int x, int p)
{
    int exp = 0;
    while(x % p == 0)
    {
        exp++;
        x /= p;
    }
    return exp;
}

pair<int, int> pttsnt(int x)
{
    int max_exp = 0;
    int max_prime = 0;
    
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            int exp = highest_power(x, i);
            if(exp > max_exp)
            {
                max_exp = exp;
                max_prime = i;
            }
            x /= pow(i, exp); 
        }
    }
    
    if(x > 1) 
    {
        if(1 > max_exp)
        {
            max_exp = 1;
            max_prime = x;
        }
    }
    
    return {max_prime, max_exp};
}
ll my_pow(int n, int k)
{
    if(k == 0)return 1;
    if(k == 1)return n;

    ll res = my_pow(n, k/2);
    res = res * res;
    if(k % 2 == 1)res *= n;
    return res;
}
void sol()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll lcm_result = a[0];
    for(int i = 1; i < n; i++)
    {
        ll gcd_val = __gcd(lcm_result, a[i]);
        lcm_result = (lcm_result / gcd_val) % MOD;
        lcm_result = (lcm_result * (a[i] % MOD)) % MOD;
    }
    
    cout << lcm_result;
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
