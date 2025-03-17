#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("MCOUNT.INP", "r", stdin);
    freopen("MCOUNT.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
}
const int MOD = 1e9+7;
ll n, x;
vector<ll> a(n);
ll res = 0;
vector<ll> current;
vector<int> cnt;
vector<bool> mark(n * x, false);
/*void gen_nor(ll idx)
{
    if(!current.empty()){
        ll val = 1;
        for(auto i : current)
        {
            val *= i;
        }
        if(val <= x){
            cnt.push_back(val);
        }
        else return;
    }
    for(int i = idx; i < n; i++)n
    {
        ll currval = a[i];
        current.push_back(currval);
        gen_nor(i+1);
        current.pop_back();
    }
}*/
// 2 1 3 4 5
void gen(ll value, ll idx, ll cnt)
{
    if (value > x) return;
    if (cnt > 0) 
    {
        res++;
    }
    for (int i = idx; i < n; i++)
    {
        gen(value * a[i], i + 1, cnt+1); 
    }
}
signed main()

{
    init();
    cin>>n>>x;
    ll cnt1 = 0;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i] == 1)cnt1++;
    }
    if(cnt1 == n){ // sub2
        ll res = 1;
        for(int i = 1; i <= n; i++)
        {
            res = (res*2)%MOD;
        }
        cout<<res-1;
        return 0;
    }
    gen(1,0,0);
    cout<<res%MOD;

}
