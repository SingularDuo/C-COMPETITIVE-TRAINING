#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        sort(a.begin(), a.end());
        ll res = LLONG_MAX;
        for(int i = 1; i < n; i++)
        {
            res = min(res, a[i] - a[i-1]);
        }
        cout<<res<<endl;
    }
}
/*

2
3
347
269
112
7
34
56
78
90
12
139
100
*/
