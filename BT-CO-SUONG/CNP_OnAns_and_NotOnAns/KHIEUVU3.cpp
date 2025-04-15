#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init(){
    freopen("KHIEUVU3.inp","r",stdin);
    freopen("KHIEUVU3.out","w",stdout);
    fast;
}

KING_PHAT
{
    init();
    fast;
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll res = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        int need = a[i] + k;
        auto it = lower_bound(a.begin(), a.end(), need);
        if(*it == need && it != a.end())res++;
    }
    cout<<res;
}