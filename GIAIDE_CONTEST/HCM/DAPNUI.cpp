#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define int long long
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    vector<ll> sub = a;
    int res = 1e18*2;
    for(int i = 1; i < n-1; i++)
    {
        ll curr = 0;
        for(int j = 1; j < i; j++)
        {
            if(a[j] <= a[j-1])
            {
                ll v = abs(a[j] - a[j-1]) + 1;
                curr += v;
                a[j] += v;
            }
        }
        //cout<<"curr after adjust left: "<<curr<<endl;
        for(int j = n-2; j > i; j--)
        {
            if(a[j] <= a[j + 1])
            {
                ll v = abs(a[j] - a[j+1]) + 1;
                curr += v;
                a[j] += v;
            }
        }
        //cout<<"curr after adjust right: "<<curr<<endl;
        ll more = max(a[i-1], a[i+1]);
        if(more >= a[i])
        {
            //cout<<"add to a[i]: "<<abs(more - a[i]) + 1<<endl;
            curr += abs(more - a[i]) + 1;
            a[i] += abs(more - a[i]) + 1;
        }
        //cout<<"curr: "<<curr<<endl;
        //for(auto& i : a)cout<<i<<" ";
        //cout<<endl;
        a = sub;
        res = min(res, curr);
        //cout<<endl;
    }
    cout<<res;
}
