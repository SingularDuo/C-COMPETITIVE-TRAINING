#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second 
#define sw(a, b) swap(a, b)

signed main()
{
    int n; cin>>n;
    vector<ll> a(n);
    ll max_val = LLONG_MIN, pos_max, min_val = LLONG_MAX, pos_min;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i] <= min_val)
        {
            min_val = a[i];
            pos_min = i;
        }
        if(a[i] > max_val)
        {
            max_val = a[i];
            pos_max = i;
        }
    }
    ll res = 0;
    if(pos_max < pos_min)res = pos_max + (n-1-pos_min);
    else res = pos_max + (n-1-pos_min)-1;
    cout<<res;
}