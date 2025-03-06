#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
bool duong(int n)
{
    return n > 0;
}
KING_PHAT
{
    fast;
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll maxx = LLONG_MIN, minn = LLONG_MAX;
    for(int i = 0;i < n; i++){
        cin>>a[i];
        maxx = max(maxx, a[i]);
        minn = min(maxx, a[i]);
    }
    if(maxx > 0 && minn > 0){
        ll res = 0;
        cout<<maxx-minn;
        return 0;
    }
    else if(maxx > 0 && minn < 0){
        cout<<maxx-abs(minn);
        return 0;
    }
    else if(maxx < 0 && minn < 0)
    {
        cout<<abs(maxx) - abs(minn);
    }
    else{
        cout<<0;
    }

}