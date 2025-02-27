#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define faster ios_base::sync_with_stdio(0) cin.tie(0) cout.tie(0)
#define king signed main()
bool isTri(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 1LL*(x1-x2)*(y2-y3)!=1LL*(y2-y1)*(x3-x2);
}
king
{
    ll n;
    cin>>n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> safe(n);
    for(int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                if(isTri(x[i], y[i], x[j], y[j], x[k], y[k])){
                    safe[i]++;
                    safe[j]++;
                    safe[k]++;
                    res++;
                }
            }
        }
    }
    int mn = LLONG_MAX; 
    int ans;

    for (int i = 0; i < n; i++) {
        if (safe[i] < mn) { 
            mn = safe[i]; 
            ans = i + 1; 
        }
    }
    cout<<res<<" "<<ans;


}