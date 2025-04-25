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
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i = 0;i < n;i++)
        {
            if(i != x)cout<<i<<" ";
        }
        cout<<x<<endl;
    }
}