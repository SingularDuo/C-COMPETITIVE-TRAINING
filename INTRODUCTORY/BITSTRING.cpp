#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

const int MOD = 1e9 + 7;
signed main()
{
    int n; cin>>n;

    ll res = 2;
    for(int i = 1; i < n; i++)
    {
        res  = (res%MOD * 2)%MOD;
    }
    cout<<res;


}
