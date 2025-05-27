#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
const int MAXN = 1e6;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];

    vector<ll> last(MAXN + 5, -1);
    ll res = LLONG_MAX; 
    for(int i = 0; i < n; i++)
    {
        if(last[a[i]] == -1)
        {
            last[a[i]] = i;
        }
        else
        {
            if(i - last[a[i]] < k)
            {
                res = min(res, a[i]);
            }
            last[a[i]] = i;
        }
    }
    if(res == LLONG_MAX){
        cout<<"-1";
        return 0;
    }
    cout<<res;
}