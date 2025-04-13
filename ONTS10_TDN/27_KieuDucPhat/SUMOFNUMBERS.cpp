#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("SUMOFNUMBERS.inp", "r", stdin);
    freopen("SUMOFNUMBERS.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res = 0, n;
    cin>>n;
    for(ll i = 0; i < n; i++)
    {
        ll a;
        cin>>a;
        res+=a;
    }
    cout<<res;
}
