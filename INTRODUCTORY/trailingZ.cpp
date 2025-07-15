#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll highest(int x)
{
    ll ans = 0;
    while(x % 5 == 0)
    {
        x /= 5;
        ans++;
    }
    return ans;
}
signed main()
{
    long long n; cin>>n;
    long long res = 0;

    for(int i = 5; i <= n; i+=5)
    {
        res += highest(i);
    }
    cout<<res;
}
