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
const int maxn = 1e6;
int souoc[maxn+5];
void cnt()
{
    for(int i = 0; i <= maxn; i++)souoc[i] = 0;
    for(int i = 1; i*i <= maxn; i++)
    {
        for(int j =i; j <= maxn/i; j++)
        {
            souoc[i*j]++;
            if(i != j)souoc[i*j]+=1;
        }
    }
}
vector<ll> f(maxn, 0);
void prefix()
{
    f[0] = souoc[0];
    for(int i = 1; i <= maxn; i++)f[i] = f[i-1] + souoc[i];
}
void sol()
{
    int l, r;
    cin>>l>>r;
    ll v1 = f[r];
    ll v2;
    if(l >= 1)v2 = f[l-1];
    else v2 = f[0];
    cout<<v1-v2<<endl;
}
KING_PHAT
{
    cnt();
    prefix();
    
    // set state for multitest
    multitest = true;
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