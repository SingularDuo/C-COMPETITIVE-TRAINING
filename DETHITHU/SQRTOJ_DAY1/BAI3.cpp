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
/*void gen(ll value, ll idx)
{
    if(idx >= n)return;
    if(value != 0 && value <= x && mark[value] == false)
    {
        res++;
        mark[value] = true;
    }
    for(int i = idx; i < n; i++)
    {
        gen(value * a[i], i);
    }
}*/

void gen_nor(ll idx)
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
    for(int i = idx; i < n; i++)
    {
        ll currval = a[i];
        current.push_back(currval);
        gen_nor(i+1);
        current.pop_back();
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
    }
    if(cnt1 == n){ // sub2
        ll ans = 0;
        n--;
        ll start = 1;
        while(n--){
            start = start * 2 + 1;
        }
        cout<<start%MOD<<endl;
        return 0;
    }
    gen_nor(0);
    cout<<cnt.size()%MOD;

}
