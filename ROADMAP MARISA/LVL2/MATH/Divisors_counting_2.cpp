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
const int mxn = 31625;
bool isprime[mxn+5];
vector<int> prime;
void sieve()
{
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = isprime[0] = false;
    for(int i = 2; i <= mxn; i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            for(int j = i*i; j <= mxn; j+=i)isprime[j] = false;
        }
    }
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
int demuoc(ll n) {
    if (n == 1) return 1;
    vector<int> somu;
    for (auto p : prime) {
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        if (cnt) somu.push_back(cnt);
    }
    if (n != 1) somu.push_back(1);
    int res = 1;
    for (auto i : somu) res *= (i + 1);
    return res;
}
void sol()
{
    int x;
    cin>>x;
    if(x <= maxn)cout<<souoc[x]<<endl;
    else cout<<demuoc(x)<<endl;
}
KING_PHAT
{
    sieve();
    cnt();
    //prefix();
    
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