#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("CHIAMANG.inp", "r", stdin);
    freopen("CHIAMANG.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    vector<ll> f(n+1);
    f[0] = 0;
    for(int i =1; i<= n; i++)
    {
        cin>>a[i];
        f[i] = f[i-1] + a[i];
    }
    bool found = false;
    for(int i = 1; i <= n; i++)
    {
        ll left = f[i] - f[0];
        ll right = f[n] - f[i];
        if(left == right)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}
