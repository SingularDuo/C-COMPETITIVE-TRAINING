#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
signed main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll m,a,b,c;
        cin>>m>>a>>b>>c;
        ll m1 = m, m2 = m;
        ll res = 0;
        
        if(a+b+c <= m)
        {
            cout<<a+b+c<<endl;
            continue;
        }
        else
        {
            if(a <= m)
            {
                res += a;
                m1 -= a;
            }
            else 
            {
                res += m;
                m1 = 0;
            }
        
            if(b <= m)
            {
                res += b;
                m2 -= b;
            }
            else 
            {
                res += m;
                m2 = 0;
            }
            
            ll remaining_c = min(c, m1 + m2);
            res += remaining_c;
            
            cout<<res<<endl;
        }
    }
}