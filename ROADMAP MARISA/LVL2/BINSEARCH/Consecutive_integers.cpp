#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int n;
    cin>>n;
    vector<ll> a(n);
    int minn = LLONG_MAX;
    for(int i =0; i < n; i++)
    {
        cin>>a[i];
        minn = min(minn, a[i]);
    }
    sort(a.begin(), a.end());
    for(auto i : a)cout<<i<<" ";
    cout<<endl;
    int res = 0;
    
    for(int i = 0; i < n;i++)
    {
        if(a[i] != minn)
        {
            res++;
            if(a[i] < minn)minn = a[i];
        
            
        }
        minn++;
    }
    cout<<res;
}