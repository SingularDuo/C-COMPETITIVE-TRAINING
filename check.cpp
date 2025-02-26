// code for fun this problem ez
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second
// no sieve cuz lazy
bool isprime(ll n)
{
    if(n == 1)return false;
    else if(n == 2 || n == 3)return true;
    else if(n %2 == 0 || n %3 == 0)return false;
    for(int i = 4; i*i <= n; i++)
    {
        if(n % i == 0)return false;
    }
    return true;
}
signed main()
{
    ll l, r;
    cin>>l>>r;
    // brute
    for(ll i  = l; i <= r; i++)
    {
        if(isprime(i))cout<<i<<endl;
    }
    return 0;
}
