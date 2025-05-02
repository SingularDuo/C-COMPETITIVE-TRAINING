#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max(a,b) max((ll)a, (ll)b)
#define min(a,b) min((ll)a, (ll)b)
#define int long long
signed main()
{
    int n;
    cin>>n;
    //cout<<1<<endl;
    for(int i = 1; i*i<=n;i++)
    {
        if(n%i == 0)
        {
            cout<<i<<" ";
            if(n/i!=i)cout<<n/i<<" "; 
        }
    }
    return 0;
}