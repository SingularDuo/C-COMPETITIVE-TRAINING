#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max(a,b) max((ll)a, (ll)b)
#define min(a,b) min((ll)a, (ll)b)
#define int long long
signed main()
{
    int n;
    cin>>n;
    //cout<<1<<endl;
    vector<ll> a(n);
    ll maxx = LLONG_MIN;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        maxx = max(maxx, a[i]);
    }
    vector<ll> f(maxx+3, 0);
    for(int i = 0; i < n; i++)
    {
        ll v = a[i];
        for(int j = 1; j*j <= v; j++)
        {
            if(v % j == 0)
            {
                f[j]++;
                if(v / j != j)f[v/j]++;
            }
        }
    }
    ll minn = LLONG_MIN;
    //if(n== 52053)cout<<f[1]<<endl;
    for(int i = 0; i <= maxx; i++)
    {
        if(f[i] >= 2)
        {
            minn = max(minn, i);
        }
    }
    cout<<minn;
}