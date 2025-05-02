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
    ll v1 = calc(a,b,x), v2 = calc(a,b,y), v3 = calc(a,b,z);
    ll val1 = calc(a,b,lcmm(x,y)), val2 = calc(a,b,lcmm(x,z)), val3 = calc(a,b,lcmm(y,z));
    ll total = calc(a,b,lcmm(x,lcmm(y,z)));
    ll onlyx = v1 - val1 - val2 + total;
    ll onlyy = v2 - val1 - val3 + total;
    ll onlyz = v3 - val2 - val3 + total;
    cout<<onlyx + onlyy + onlyz;
}
/**

1000/2 - 9/2 = 500 - 4 = 496
1000/3 - 10/3 = 333 - 3 = 330
1000/16 - 10/16 = 62 - 0 = 62;

BCNN 2 so
1000/6 - 10/6 = 166 - 1 = 165
1000/16 - 10/16 = 62    
1000/48 - 10/ 48 = 20 - 0 = 20

BCNN 3 so
1000/48 - 10/ 48 = 20

496 + 330 + 62 - 165 - 62 -20 + 20 = 660
660/3 = 220
=> so luong so chi chia het cho 2,3,5 bang cong thuc tinh onlyx, onlyy, onlyz
**/