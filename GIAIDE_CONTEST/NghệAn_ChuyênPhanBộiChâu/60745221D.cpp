#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int long long
#define TOISETHIVOI signed main()

const int mx = 1e5+5;
TOISETHIVOI
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<ll> a(n);
    map<int, vector<ll>> b;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        b[a[i]].push_back(i);
    }
    vector<ll> res(n);
    ll cmp = LLONG_MAX;
    for(int i = 0; i < b.size(); i++)
    {
        for(int j : b[i])
        { 
            // may cai dau tien ma k co thi nhot
            // cai phan tu nho nhat thi = 0 
            if(cmp >= j)res[j] = 0;
            else res[j] = j - cmp;
        }
        for(int j : b[i])
        {
            // doi me index len :
            if(j < cmp)cmp = j;
        }
    }
    for(int i = 0; i < n; i++)cout<<res[i]<<" ";


}