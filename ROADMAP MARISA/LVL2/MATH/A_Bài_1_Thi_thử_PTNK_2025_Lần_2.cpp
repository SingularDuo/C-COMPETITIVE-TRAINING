#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("BAI1_HUB05.inp", "r", stdin);
    freopen("BAI1_HUB05.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int lcmm(int a, int b)
{
    return (a/__gcd(a,b))*b;
}
int calc(int a, int b, int n)
{
    return (b/n) - ((a-1)/n);
}
signed main()
{
    //init();
    //cout<<lcmm(2,3)<<endl;
    int a,b,x,y,z;
    cin>>a>>b>>x>>y>>z;
    int res = calc(a,b,x) + calc(a,b,y) + calc(a,b,z);
    //cout<<res<<endl;
    //cout<<calc(a,b,lcmm(x,y))<<endl;
    //cout<<calc(a,b,lcmm(x,z))<<endl;
    //cout<< calc(a,b,lcmm(y,z))<<endl;
    res -= calc(a,b,lcmm(x,y)) + calc(a,b,lcmm(x,z)) + calc(a,b,lcmm(y,z));
    //cout<<res<<endl;
    ll v1 = lcmm(x,y);
    v1 = lcmm(v1, z);
    //cout<<v1<<endl;
    //cout<<calc(a,b,v1)<<endl;
    res += calc(a,b,v1);
    cout<<res/3;
}
/**

1000/2 - 10/2 = 500 - 5 = 495
1000/3 - 10/3 = 333 - 3 = 330
1000/16 - 10/16 = 62 - 0 = 62;

BCNN 2 so
1000/6 - 10/6 = 166 - 1 = 165
1000/16 - 10/16 = 62
1000/48 - 10/ 48 = 20 - 0 = 20

BCNN 3 so
1000/48 - 10/ 48 = 20

495 + 330 + 62 - 165 - 62 -20 + 20 = 660
660/3 = 220

**/