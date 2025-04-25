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
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n == 1)
        {
            if(s[0] == '1')
            {
                cout<<0<<endl;
                continue;
            }
            else cout<<1<<endl;
        }
        else{
            int res = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == '1')res++;
            }
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == '0')
                {
                    ans += res + 1;
                }
                else ans += res-1;
            }
            cout<<ans<<endl;
        }
    }
}