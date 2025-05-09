#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)

signed main()
{
    int n;
    cin>>n;
    // +3 lien tuc tu 2
    int add = 3;
    int start_index = 2;
    vector<ll> a(n, 0);
    vector<ll> sub;
    for(int i  = start_index; i <= n; i+=add)
    {
        sub.push_back(i);
    }
    start_index--;
    while(sub.size() > 1)
    {
        vector<ll> curr;
        for(int i = start_index; i <= sub.size(); i+=add)
        {
            //cout<<i<<" "<<sub[i]<<endl;
            curr.push_back(sub[i]);
        }
        sub = curr;
    }
    cout<<sub[0];

}