#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    fast;
}
KING_PHAT
{
    init();
    fast;
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        m = __gcd(m, abs(a[i] - a[0]));
    }
    cout<<m;
}