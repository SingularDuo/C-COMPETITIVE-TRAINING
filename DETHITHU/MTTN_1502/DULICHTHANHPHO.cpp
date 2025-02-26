#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second
using namespace std;

int main() {
    ll n,k;
    cin>>n>>k;
    vector<pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ll res = a[0].first, lastvalue = a[0].first, lastpos = 0;
    for(ll i =1; i < n; i++)
    {
        if(a[i].second > lastpos && a[i].first > lastvalue)
        {
            lastpos = i;
            lastvalue = a[i].first;
            res += a[i].first;
        }
        else if(lastvalue > a[i].first && a[i].second > lastpos && k > 0)
        {
            lastvalue = a[i].first;
            lastpos = i;
            k--;
            res += a[i].first;
        }
    }
    cout<<res;

    return 0;
}
