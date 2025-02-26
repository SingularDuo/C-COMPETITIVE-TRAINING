 #include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    sad
    ll s, n;
    cin>>s>>n;
    vector<pair<ll, ll>> a(s);
    for(int i = 0; i < s; i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end());
    ll idx = 0;
    ll res = 0;
    ll constn = n;
    while(a[idx].first < n && idx <= constn-1)
    {
        res++;
        n += a[idx].second;
        idx++;

    }
    cout<<res;
}
// 50% test
