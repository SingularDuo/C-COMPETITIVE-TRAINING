#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
vector<ll> uoc(int x)
{
    vector<ll> res;
    for(int i = 1; i < x; i++)
    {
        if(x % i == 0) res.push_back(i);
    }
    res.push_back(x);
    return res;
}
signed main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0 ; i < n; i++)cin>>a[i];
    map<int, int> cnt;
    for(int i = 0; i < n; i++)
    {
        vector<ll> current = uoc(a[i]);
        for(auto j : current)cnt[j]++;
    }
    ll maxx = LLONG_MIN;
    for(auto& i : cnt)
    {
        if(i.second == n - 1)
        {
            maxx = max(maxx, i.first);
        }
    }
    cout<<maxx;
}