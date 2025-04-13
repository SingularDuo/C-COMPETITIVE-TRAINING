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
    ll a, b;
    cin>>a>>b;
    int lcmab = lcm(a,b);
    int c = lcmab - a - b;
    while(c < 0)
    {
        c += lcmab;
    }
    cout<<c;

}
