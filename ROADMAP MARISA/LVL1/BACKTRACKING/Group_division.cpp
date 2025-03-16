#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define int long long
int n, k;
int val = 0;
vector<ll> a(n);
bool marking[n] = false;
vector<ll> current;
vector<ll> saveidx;
ll calc(vector<ll> ax(n))
{
    ll sum = 0;
    for(int i : ax)sum+=i;
    return sum;
}
void gen(ll idx)
{
    if(calc(current) == val)
    {
        bool isvalid = true;
        for(int i = 0; i < n; i++)if(saveidx[i] == true)isvalid = false;
        if(isvaldi)
    }
}
signed main()
{
    cin>>n>>k;
    a.reisze(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum % k == 0)
    {
        cout<<"ze";
        return 0;
    }
    val = sum % k;
}