#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("TVKVN.INP","r",stdin);
    freopen("TVKVN.OUT","w",stdout);
    fast;
}
KING_PHAT
{
    init();
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll maxx = 0;
    for(auto i : mp)
    {
        maxx = max(maxx, i.second);
    }
    for(auto i : mp)
    {
        if(i.second == maxx)
        {
            cout << i.first<<endl;
        }
    }
    return 0;
}