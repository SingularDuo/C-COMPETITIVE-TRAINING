#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a, b, c, res= 0;
    cin>>a>>b>>c;
    ll minn = min(a,b);
    res += minn;
    a -= minn;
    b-=minn;
    res += a/3;
    res += c;
    cout<<res;
}
