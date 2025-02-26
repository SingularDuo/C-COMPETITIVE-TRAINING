#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll find_c(ll a, ll b, ll x)
{
    ll sum =  x* 3;
    ll c = sum - a- b;
    return c;
}
int main()
{
    ll a, b, x;
    cin>>a>>b>>x;
    ll res = find_c(a,b,x);
    cout<<res;
}
