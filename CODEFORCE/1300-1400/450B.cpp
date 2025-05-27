#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define TOISETHIVOI signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
bool multitest = false;
const int MOD = 1e9+7;
void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

void sol() {
    int a, b, t; 
    cin >> a >> b >> t;

    ll s[] = {a, b, b - a, -a, -b, a - b};
    cout << (s[(t - 1) % 6] % MOD + MOD) % MOD;
}

TOISETHIVOI
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