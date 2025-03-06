#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("PCB.INP", "r", stdin);
    freopen("PCB.OUT", "w", stdout);
    fast;
}
KING_PHAT
{
    init();
    fast;
    int n;
    cin>>n;
    vector<ll> a;
    ll alice, bob;
    for(int i = 1; i <= n; i++)
    {
        ll x,y,v;
        cin>>x>>y>>v;
        alice = x, bob = y;
        a.push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 != 0)
        {
            while((bob-alice)%i != 0)
            {
                bob++;
            }
            cout<<alice<<" "<<bob<<endl;
        }
        else{
            while((bob-alice)%i != 0){
                alice--;
            }
            cout<<alice<<" "<<bob<<endl;
        }
    }
    return 0;
}
