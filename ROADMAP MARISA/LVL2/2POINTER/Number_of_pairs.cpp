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
    int n, x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    int it1 = 0, it2 = n - 1;
    int res = 0;
    while(it1 < it2)
    {
        if(a[it1] + a[it2] > x)it2--;
        else if(a[it1] + a[it2] == x)
        {
            res++;
            it2--;
        }
        else it1++;
    }
    cout<<res;
}