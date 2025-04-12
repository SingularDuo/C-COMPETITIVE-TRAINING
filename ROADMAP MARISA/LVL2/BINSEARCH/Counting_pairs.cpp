#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int n, l, r;
    cin>>n>>l>>r;
    vector<ll> a(n+1);
    map<int, int> cnt;
    for(int i = 1; i <= n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    ll res = 0;
    for(int i =1; i <= n; i++)
    {
        ll minn = l - a[i];
        ll maxx = r - a[i];
        auto it = lower_bound(a.begin()+i+1, a.end(), minn);
        auto it2 = upper_bound(a.begin()+i+1, a.end(), maxx);
        res += it2 - it;
    }
    cout<<res;
    
}