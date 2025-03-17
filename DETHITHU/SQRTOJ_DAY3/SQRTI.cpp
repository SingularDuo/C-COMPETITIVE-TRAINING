#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("SQRTRI.inp", "r", stdin);
    freopen("SQRTRI.out", "w", stdout);
    ios_base::sync_with_stdio(0);
}
bool scp(int x)
{
    if (x < 0) return false; 
    long long k = sqrt(x);
    return k * k == x;
}
KING_PHAT
{
    fast;
    init();
    int n, q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    if(n <= 500 && q == 1)
    {
        while(q--)//sub1
        {
        ll l, r;
        cin>>l>>r;
        l--;
        r--;
        ll res = 0;
        for(int i = l; i <= r; i++)
        {
            for(int j = i+1; j <= r; j++)
            {
                for(int l = j+1; l <= r; l++)
                {
                    ll curr = a[i] * a[j] * a[l];
                    if(scp(curr))res++;

                }
            }
        }
        cout<<res<<endl;
        }
    }
    
}