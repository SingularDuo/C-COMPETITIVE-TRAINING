#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin>>n;
    vector<pair<ll, ll>> a(n);
    for(ll i =  0 ; i < n; i++)
    {
        a[i].first = i;
        cin>>a[i].second;
    }
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i].second > 1)
        {
            if(a[i].second % 2 == 0)
            {
                res += a[i].second/2;
                a[i].second = 0;
            }
            else{
                res+= (a[i].second - 1 )/2;
                a[i].second = 1;
            }
        }
    }
    ll cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i].second > 0)
        {
            cnt++;
        }
    }
    res += cnt/2;
    cout<<res;
    return 0;
}
