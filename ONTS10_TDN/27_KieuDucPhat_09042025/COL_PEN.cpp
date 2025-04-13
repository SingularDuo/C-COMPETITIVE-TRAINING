#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("COL_PEN.INP", "r", stdin);
    freopen("COL_PEN.OUT", "w", stdout);
    set<ll> cnt;
    for(ll i = 0; i < 4; i++)
    {
        ll a;
        cin>>a;
        cnt.insert(a);
    }
    cout<<4-cnt.size();
}
