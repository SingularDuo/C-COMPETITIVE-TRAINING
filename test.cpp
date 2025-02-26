#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define int long long
// sang nguyen to
const int maxn = 1e5; // dieu chinh theo bai
bool isprime[maxn];
void sieve(){
    for(int i = 0; i <= maxn; i++)isprime[i]=true;
    isprime[1]= isprime[0] = false;
    for(int i = 2; i*i <= maxn; i++)
    {
        if(isprime[i] == true)
        {
            for(int j = i*i; j <= maxn; j += i)
            {
                isprime[i] = false;
            }
        }
    }
}
signed main()
{
    sieve();
    ll a;
    cin>>a;
    if(isprime[a])cout<<"YES";
    else cout<<0;

}