#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("MULARR.INP","r",stdin);
    freopen("MULARR.OUT","w",stdout);
    faster;
}
signed main(){
    init();
    ll n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> f(n);
    f[0] = a[0];
    for(int i=1; i<n; i++) f[i] = f[i-1] + a[i];
    ll res = 0;
    for(int i=0; i<n;i++)
    {
        ll sum = f[n -1] - f[i];
        res += a[i] * sum;
    }
    cout<<res;
}