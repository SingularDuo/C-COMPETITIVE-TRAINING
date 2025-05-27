#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl "\n"

signed main()
{
    int n, m ,k; cin>>n>>m>>k;

    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < m; i++)cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int pA = 0, pB = 0, res = 0;
    while(pA < n && pB < m)
    {
        if(abs(a[pA] - b[pB]) <= k)
        {
            res++;
            pA++;
            pB++;
        }
        else if(a[pA] < b[pB])pA++;
        else pB++;
    }
    cout<<res;
}