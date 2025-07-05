#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

signed main()
{
    int n; cin>>n;
    vector<pair<int, int>> a(n);
    vector<ll> b;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second;
        b.push_back(a[i].first);
        b.push_back(a[i].second);
    }
    sort(b.begin(), b.end());
    
}