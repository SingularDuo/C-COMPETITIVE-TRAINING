#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define min(a,b) min((ll)a, (ll)b)
#define max(a,b) max((ll)a, (ll)b)
const int MOD = 1e9 + 7;
const int maxn = 2 * 1e5;
const int maxm = 1e9;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    vector<ll> sub(n, 0);
    for(int i = 0; i < m; i++)
    {
        int r;
        cin>>r;
        ll res = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[j] >= r)
            {
                res += r;
                a[j] -= r;
            }
            else if(a[j] == 0)continue;
            else{
                res += a[j];
                a[j] = 0;
            }
        }
        
        cout<<res<<" ";
        if(a==sub)
        {
            return 0;
        }
    }
}