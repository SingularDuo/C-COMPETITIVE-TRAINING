#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl "\n"
#define fi first
#define se second
const int maxn = 1e7;
void init(){
    freopen("Math.INP", "r", stdin);
    freopen("Math.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vector<bool> isprime(maxn + 1, true);
vector<int>primes;
void sieve(int n)
{
    isprime[0] = isprime[1] = false;
    for(int i = 2; i * i <= n; i++)
    {
        if(isprime[i])
        {
            for(int j = i*i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(isprime[i] == true)primes.push_back(i);
    }
}
signed main()
{
    init();

    ll n;
    cin>>n;
    sieve(n);
    for(int z : primes){
        if(z > n)break;
        for(int x : primes){
            if(x*x >= z)break;
            int y2 = z - x*x;
            int y = sqrt(y2);
            if(isprime[y] && y*y == y2 && x <= y){
                cout<<x<<" "<<y<<" "<<z<<endl;
            }
        }
    }
}
